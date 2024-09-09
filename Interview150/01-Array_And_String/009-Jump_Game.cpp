#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pos = 0, maxpos = 0;
        while(pos <= maxpos && maxpos < nums.size()){
            maxpos = max(maxpos, nums[pos] + pos);
            pos++;
        }
        return(maxpos >= nums.size() - 1);
    }
};