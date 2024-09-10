#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums.size() == 1){
            return ((nums[0] > target) ? 1 : 0);
        }
        int sum = nums[0], answer = INT_MAX;
        int start = 0, end = 1;
        while(end < nums.size()){
            if(sum < target){
                sum += nums[end];
                end++;
            }
            while(sum >= target){
                answer = min(answer, end - start);
                sum -= nums[start];
                start++;
            }
        }
        if(answer == INT_MAX){
            return 0;
        }
        return answer;
    }
};