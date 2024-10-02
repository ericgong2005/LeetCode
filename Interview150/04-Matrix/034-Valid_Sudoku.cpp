#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            vector<char> nums;
            vector<char> nums2;
            for(int j = 0; j < 9; j++){
                if(isdigit(board[i][j])){
                    if(find(nums.begin(), nums.end(), board[i][j]) != nums.end()){
                        return false;
                    }
                    nums.push_back(board[i][j]);
                }
                if(isdigit(board[j][i])){
                    if(find(nums2.begin(), nums2.end(), board[j][i]) != nums2.end()){
                        return false;
                    }
                    nums2.push_back(board[j][i]);
                }
            }
        }
        for(int i = 0; i < 3; i++){
            for(int ii = 0; ii < 3; ii++){
                vector<char> nums;
                for(int j = 0; j < 3; j++){
                    for(int jj = 0; jj < 3; jj++){
                        if(isdigit(board[i*3 + j][ii*3 + jj])){
                            if(find(nums.begin(), nums.end(), 
                                board[i*3 + j][ii*3 + jj]) != nums.end()){
                                return false;
                            }
                            nums.push_back(board[i*3 + j][ii*3 + jj]);
                        }
                    }
                }
            }
        }
        return true;
    }
};