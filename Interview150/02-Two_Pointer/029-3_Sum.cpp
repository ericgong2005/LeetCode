#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        if(nums.size() < 3){
            return answer;
        }
        sort(nums.begin(), nums.end());
        int target;
        for(int i = 0; i < nums.size() - 2; i++){
            target = 0 - nums[i];
            int lpos = i + 1, rpos = nums.size() - 1, current;
            while(lpos < rpos){
                current = nums[lpos] + nums[rpos];
                if(current == target){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[lpos]);
                    temp.push_back(nums[rpos]);
                    answer.push_back(temp);
                    while(lpos < rpos && nums[lpos + 1] == nums[lpos]){
                        lpos++;
                    }
                    while(lpos < rpos && nums[rpos - 1] == nums[rpos]){
                        rpos--;
                    }
                }
                if(current > target){
                    rpos--;
                }
                else{
                    lpos++;
                }
            }
            while(i < nums.size() - 3 && nums[i + 1] == nums[i]){
                i++;
            }
        }
        return answer;
    }
};