//solution 1:

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector <long long> divides;
        for (int i = 1; i < (int)weights.size(); ++i){
            divides.push_back(weights[i] + weights[i - 1]);
        }
        sort(divides.begin(), divides.end());
        long long res = 0;
        for (int i = divides.size() - 1; i >= (int)divides.size() - k + 1; --i)
            res += divides[i];
        
        for (int i = 0; i < k - 1; ++i)
            res -= divides[i];

        return res;
    }
};
