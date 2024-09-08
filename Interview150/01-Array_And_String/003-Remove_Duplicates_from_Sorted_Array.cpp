#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int check = 1, add = 1;
        while(check < nums.size()){
            if(nums[check] != nums[check - 1]){
                nums[add] = nums[check];
                add++;
            }
            check++;
        }
        return add;
    }
};