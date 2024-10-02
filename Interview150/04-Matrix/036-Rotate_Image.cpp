#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n < 2){
            return;
        }
        for(int i = 0; i < n / 2; i++){
            for(int ii = 0; ii < n / 2 + n % 2; ii++){
                swap(matrix[i][ii], matrix[n - ii - 1][i]);
                swap(matrix[n - ii - 1][i], matrix[n - i - 1][n - ii - 1]);
                swap(matrix[n - i - 1][n - ii - 1], matrix[ii][n - i - 1]);
            }
        }
    }
};