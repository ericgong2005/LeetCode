#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size() < 2){
            return ratings.size();
        }
        vector<int> forward;
        int acc = 0;
        forward.push_back(0);
        for(int i = 1; i < ratings.size(); i++){
            if(ratings[i] > ratings[i - 1]){
                acc++;
                forward.push_back(acc);
            }
            else{
                acc = 0;
                forward.push_back(0);
            }
        }
        int total = 1 + forward[ratings.size() - 1];
        for(int i = ratings.size() - 2; i >= 0; i--){
            if(ratings[i + 1] < ratings[i]){
                acc++;
                total += 1 + max(forward[i], acc);
            }
            else{
                acc = 0;
                total += 1 + forward[i];
            }
        }
        return total;
    }
};