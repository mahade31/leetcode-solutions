//solution 1:

class Solution {
public:
    bool is_palindrome(string s){
        for (int i = 0; i < (int)s.length() / 2; ++i){
            if (s[i] != s[s.length() - 1 - i])
                return false;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        int len = s.length();
        vector <vector <string>> ret;

        for (int i = 1; i < (1 << len); ++i){
            vector <string> vec;
            string temp;
            for (int j = 0; j < len; ++j){
                temp += s[j];
                if ((i & (1 << j))){
                    if (is_palindrome(temp))
                        vec.push_back(temp);
                    else{
                        vec.clear();
                        break;
                    }
                    temp = "";
                }
            }
            if (!vec.empty() and (i & (1 << (len - 1))))
                ret.push_back(vec);       
        }
        return ret;
    }

};
