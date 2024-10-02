#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool mzero = false, nzero = false;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0){
                mzero = true;
            }
        }
        for(int i = 0; i < n; i++){
            if(matrix[0][i] == 0){
                nzero = true;
            }
        }
        for(int i = 0; i < m; i++){
            for(int ii = 0; ii < n; ii++){
                if(matrix[i][ii] == 0){
                    matrix[0][ii] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < m; i++){
            if(matrix[i][0] == 0){
                for(int ii = 1; ii < n; ii++){
                    matrix[i][ii] = 0;
                }
            }
        }
        for(int i = 1; i < n; i++){
            if(matrix[0][i] == 0){
                for(int ii = 1; ii < m; ii++){
                    matrix[ii][i] = 0;
                }
            }
        }
        if(mzero){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }
        if(nzero){
            for(int i = 0; i < n; i++){
                matrix[0][i] = 0;
            }
        }
    }
};