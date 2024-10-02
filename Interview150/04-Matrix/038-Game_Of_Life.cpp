#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        //0 = 0->0; 1 = 1->1; -1 = 1->0; 2 = 0->1;
        unordered_map<int, int> current ({{0,0}, {1,1}, {-1,1}, {2,0}});
        unordered_map<int, int> next ({{0,0}, {1,1}, {-1, 0}, {2,1}});
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int neighbors = 0;
                for(int ii = i - 1; ii < i + 2; ii++){
                    for(int jj = j - 1; jj < j + 2; jj++){
                        if(ii >= 0 && ii < m && jj >= 0 && jj < n){
                            if(ii != i || jj != j){
                                neighbors+=current[board[ii][jj]];
                            }
                        }
                    }
                }
                if(board[i][j]){
                    if(neighbors < 2 || neighbors > 3){
                        board[i][j] = -1;
                    }
                }
                else if(neighbors == 3){
                    board[i][j] = 2;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                board[i][j] = next[board[i][j]];
            }
        }
    }
};