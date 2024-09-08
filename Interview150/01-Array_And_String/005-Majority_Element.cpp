#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0], current = 1, other = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == majority){
                current++;
            }
            else{
                other++;
                if(other == current){
                    other = 0;
                    current = 1;
                    majority = nums[i];
                }
            }
        }
        return majority;
    }
};