#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> before;
        before.push_back(1);
        for(int i = 0; i < nums.size() - 1;i++){
            before.push_back(before[i]*nums[i]);
        }
        int after = 1;
        for(int i = nums.size() - 1; i >=0; i--){
            before[i] = before[i]*after;
            after = after*nums[i];
        }
        return before;
    }
};