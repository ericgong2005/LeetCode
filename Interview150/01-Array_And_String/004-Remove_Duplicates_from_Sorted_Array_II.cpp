#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 3){
            return nums.size();
        }
        int check = 2, add = 2;
        while(check < nums.size()){
            if(nums[check] != nums[add - 2]){
                nums[add] = nums[check];
                add++;
            }
            check++;
        }
        return add;
    }
};