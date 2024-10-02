#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int upb = 0, lowb = matrix.size() - 1;
        int leftb = 0, rightb = matrix[0].size() - 1;
        while(upb < lowb && leftb < rightb){
            result.push_back(matrix[upb][leftb]);
            for(int i = leftb + 1; i < rightb; i++){
                result.push_back(matrix[upb][i]);
            }
            result.push_back(matrix[upb][rightb]);
            for(int i = upb + 1; i < lowb; i++){
                result.push_back(matrix[i][rightb]);
            }
            result.push_back(matrix[lowb][rightb]);
            for(int i = rightb - 1; i > leftb; i--){
                result.push_back(matrix[lowb][i]);
            }
            result.push_back(matrix[lowb][leftb]);
            for(int i = lowb - 1; i > upb; i--){
                result.push_back(matrix[i][leftb]);
            }
            upb++;
            lowb--;
            leftb++;
            rightb--;
        }
        if(upb == lowb){
            if(leftb <= rightb){
                result.push_back(matrix[upb][leftb]);
            }
            if(leftb < rightb){
                for(int i = leftb + 1; i < rightb + 1; i++){
                    result.push_back(matrix[upb][i]);
                }
            }
        }
        else if(leftb == rightb){
            if(upb <= lowb){
                result.push_back(matrix[upb][rightb]);
            }
            if(upb < lowb){
                for(int i = upb + 1; i < lowb + 1; i++){
                    result.push_back(matrix[i][rightb]);
                }
            }
            return result;
        }
        return result;
    }
};