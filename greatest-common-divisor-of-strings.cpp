class Solution {
public:
    bool div(string a, string b){
        string temp = b;
        while (temp.length() < a.length())
            temp += b;
        return temp == a;
    }
    string gcdOfStrings(string str1, string str2) {
        string temp = "";
        string ret = "";
        for (char c : str1){
            temp += c;
            if (div(str1, temp) and div(str2, temp)){
                ret = temp;
            }
        }
        return ret;
    }
};
