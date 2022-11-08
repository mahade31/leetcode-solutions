/*
Problem: https://leetcode.com/problems/make-the-string-great/

Editorial:
We can use stack to solve the problem. 
We iterate through every character of the string, and for each character we see if the top character of the stack is matched with the current character. If matched, we pop the top character and go to the next character. Here two character is said to be mathced if one of them is uppercase and the other one is lowercase also they are the same alphabet. 

*/

class Solution {
public:
    bool match(char c, char d){
        if (isupper(c) == isupper(d))
            return false;
        return (tolower(c) == tolower(d));
    }
    string makeGood(string s) {
        stack <char> st;
        for (char c : s){
            if (!st.empty() and match(st.top(), c))
                st.pop();
            else
                st.push(c);
        }
        string ret = "";
        while (!st.empty()){
            ret += st.top();
            st.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
