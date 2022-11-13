/*
Problem: https://leetcode.com/problems/find-median-from-data-stream/

Editorial:
This problem can be solved using Segment Tree or Binary Indexed Tree or Policiy Based Data 
Structure but here we will talk about a trickier and simple solution.

We will solve the problem using two heaps, one is max heap another is min heap.

We will maintain the heaps in such a way that after being sorted first half of the elements
are stored in a max heap and another half in stored in a min heap.

That way we can always get two middle elements of current numbers.
So when addNum is called we add it in the heap which is less in size. Then if necessery we
swap the two top elements to maintain the two halves property.

So complexity of each operation in O(logn). Thus overall time complexity is O(nlogn).
And space complexity is O(n) cause we will use store at most n numbers in the heap.

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
