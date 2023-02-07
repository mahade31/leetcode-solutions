//solution 1:

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        set <int> st;
        int count[fruits.size()];
        memset(count, 0, sizeof count);
        int ans = 1;
        for (int i = 0, j = 0; j < fruits.size(); ++j){
            st.insert(fruits[j]);
            ++count[fruits[j]];
            while (st.size() > 2){
                --count[fruits[i]];
                if (count[fruits[i]] == 0){
                    auto it = st.find(fruits[i]);
                    if (it != st.end())
                        st.erase(it);
                }
                ++i;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};

//solution 2:

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int taken = 0;
        int count[fruits.size()];
        memset(count, 0, sizeof count);
        int ans = 1;
        for (int i = 0, j = 0; j < fruits.size(); ++j){
            ++count[fruits[j]];
            if (count[fruits[j]] == 1)
                ++taken;
            while (taken > 2){
                --count[fruits[i]];
                if (count[fruits[i]] == 0)
                    --taken;
                ++i;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
