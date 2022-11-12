/*
Problem: https://leetcode.com/problems/find-median-from-data-stream/

Solution:
*/
class MedianFinder {
public:
    priority_queue <int, vector<int>, greater<int>> min_heap;
    priority_queue <int> max_heap; 
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (min_heap.size() <= max_heap.size()){
            min_heap.push(num);
        }
        else{
            max_heap.push(num);
        }
        if (!min_heap.empty() and !max_heap.empty() and min_heap.top() < max_heap.top()){
            int x = min_heap.top();
            min_heap.pop();
            int y = max_heap.top();
            max_heap.pop();
            min_heap.push(y);
            max_heap.push(x);
        }
    }
    
    double findMedian() {
        double ans;
        if (min_heap.size() == max_heap.size()){
            ans = min_heap.top() + max_heap.top();
            ans /= 2;
        }
        else if (min_heap.size() < max_heap.size()){
            ans = max_heap.top();
        }
        else {
            ans = min_heap.top();
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
