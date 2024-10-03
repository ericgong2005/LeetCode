#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> list;
        if(k == 0){
            return false;
        }
        if(k >= nums.size()){
            k = nums.size() - 1;
        }
        for(int i = 0; i <= k; i++){
            list[nums[i]]++;
            if(list[nums[i]] > 1){
                return true;
            }
        }
        for(int i = k + 1; i < nums.size(); i++){
            list[nums[i - k - 1]]--;
            list[nums[i]]++;
            if(list[nums[i]] > 1){
                return true;
            }
        }
        return false;
    }
};