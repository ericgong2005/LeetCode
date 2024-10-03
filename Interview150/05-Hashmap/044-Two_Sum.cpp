#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> sorted;
        for(int i = 0; i < nums.size(); i++){
            sorted.push_back(make_pair(nums[i], i));
        }
        sort(sorted.begin(), sorted.end());
        int l = 0, r = nums.size() - 1;
        vector<int> answer;
        while(l < r){
            if(sorted[l].first + sorted[r].first < target){
                l++;
            }
            else if(sorted[l].first + sorted[r].first > target){
                r--;
            }
            else{
                answer.push_back(sorted[l].second);
                answer.push_back(sorted[r].second);
                break;
            }
        }
        return answer;
    }
};