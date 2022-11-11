/*
Problem: https://leetcode.com/problems/online-stock-span/

Editorial:
If you understood the problem, you can see that the solution needs to find is: starting from i 
what is first position whose value is larger than the value of i-th if you start going to left from i. 
For example: 
7 8 9 2 3 4 5
1 2 3 4 5 6 7
    j     i
          
If i is 6 then you need to find j = 3. You need to do this for every position i.

We can do this in naive approach in O(n^2) but that will not run in the given time limit.

It requires O(nlogn) or O(n) solution.

Using binary search and segment tree data structure this can be solved in O(nlogn). 
That can be another tutorial. 

Here we will talk about a simpler solution which is better in terms of time complexity too.

We will use stack to solve this problem. I assume you know what is stack and what are its operations.

To solve this problem what we will maintain is called a monotonic stack. [https://medium.com/@vishnuvardhan623/monotonic-stack-e9dcc4fa8c3e]

Here we will maintain a decreasing stack. 

Initially we push a max value to the stack. Then for each number or price we get we keep popping the numbers 
which are less or equal to the current number. When we find a number in top of the stack which is greater 
than the current number we know all of the numbers which are in right postions from this are smaller or equal than the current number.
Also we need to keep the indices of the numbers too in the stack. We calculate the answer and push the current number to the stack. 
Or we can maintain a different stack for that if we want.

Notice that each number will at most be pushed in queue once and popped once. So the time complexity is O(n). 
Also the queue can contain at most n numbers. So the auxiliary space will be taken at most is n. So, space complexity is O(n) too.

Solution:
*/



class StockSpanner {
public:
    stack <pair<int, int>> st;
    int len;
    StockSpanner() {
        st.push({100005, 0});
        len = 1;
    }
    
    int next(int price) {
        while (st.top().first <= price){
            st.pop();
        }
        int ans = len - st.top().second;
        st.push({price, len});
        ++len;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
