#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int check = 0, add = 0;
        while(check < nums.size()){
            if(nums[check] != val){
                nums[add] = nums[check];
                add++;
            }
            check++;
        }
        return add;
    }
};