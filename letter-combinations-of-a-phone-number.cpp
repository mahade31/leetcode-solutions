//problem: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector <string> mapping = {"", "", "abc", "def", 
        "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        int len = digits.size();
        vector <string> ret;
        if (len == 1) {
            for (char a : mapping[digits[0] - '0']) {
                string temp = "";
                temp += a;
                ret.push_back(temp);
            }
        }
        else if (len == 2) {
            for (char a : mapping[digits[0] - '0']) {
                for (char b : mapping[digits[1] - '0']) {
                    string temp = "";
                    temp += a;
                    temp += b;
                    ret.push_back(temp);
                }
            }
        }
        else if (len == 3) {
            for (char a : mapping[digits[0] - '0']) {
                for (char b : mapping[digits[1] - '0']) {
                    for (char c : mapping[digits[2] - '0']) {
                        string temp = "";
                        temp += a;
                        temp += b;
                        temp += c;
                        ret.push_back(temp);
                    }
                }
            }
        }
        else if (len == 4) {
            for (char a : mapping[digits[0] - '0']) {
                for (char b : mapping[digits[1] - '0']) {
                    for (char c : mapping[digits[2] - '0']) {
                        for (char d : mapping[digits[3] - '0']) {
                            string temp = "";
                            temp += a;
                            temp += b;
                            temp += c;
                            temp += d;
                            ret.push_back(temp);
                        }
                    }
                }
            }
        }
        return ret;
    }
};
