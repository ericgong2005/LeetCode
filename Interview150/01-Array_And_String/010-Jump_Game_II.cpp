#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1){
            return 0;
        }
        int curmax = 0, nextmax = nums[0], jumps = 0;
        for(int i = 0; i < nums.size() && curmax < nums.size(); i++){
            if(i > curmax){
                curmax = nextmax;
                jumps++;
            }
            nextmax = max(nextmax, i + nums[i]);
        }
        return jumps;
    }
};