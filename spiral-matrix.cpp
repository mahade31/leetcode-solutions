//problem: https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector <int> ret;
        int x1 = 0, y1 = 0, x2 = row - 1, y2 = col - 1;
        while (x1 < x2 and y1 < y2){
            for (int j = y1; j < y2; ++j){
                ret.push_back(matrix[x1][j]);
            }
            for (int i = x1; i < x2; ++i){
                ret.push_back(matrix[i][y2]);
            }
            for (int j = y2; j > y1; --j){
                ret.push_back(matrix[x2][j]);
            }
            for (int i = x2; i > x1; --i){
                ret.push_back(matrix[i][y1]);
            }
            ++x1, ++y1;
            --x2, --y2;
        }
        while (x1 <= x2 and y1 == y2){
            ret.push_back(matrix[x1++][y1]);
        }
        while (y1 <= y2 and x1 == x2){
            ret.push_back(matrix[x1][y1++]);
        }
        return ret;
    }
};
