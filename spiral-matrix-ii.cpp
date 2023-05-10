//problem: https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int matrix[n][n];
        int row = 0, col = n - 1;
        int cnt = 0;
        while (true){
            if (row == col){
                matrix[row][col] = ++cnt;
                break;
            }
            for (int j = row; j < col; ++j){
                matrix[row][j] = ++cnt;
            }

            for (int i = row; i < col; ++i){
                matrix[i][col] = ++cnt;
            }

            for (int j = col; j > row; --j){
                matrix[col][j] = ++cnt;
            }

            for (int i = col; i > row; --i){
                matrix[i][row] = ++cnt;
            }

            ++row;
            --col;
            if (cnt == n * n)
                break;
        }
        vector<vector<int>> ret;
        for (int i = 0; i < n; ++i){
            vector <int> vec;
            for (int j = 0; j < n; ++j){
                vec.push_back(matrix[i][j]);
            }
            ret.push_back(vec);
        }
        
        return ret;
    }
};
