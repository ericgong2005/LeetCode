#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> answer;
        int index = 0;
        for(int i = 1; i < nums.size();i++){
            if(nums[i] != nums[i-1] + 1){
                if(index == i - 1){
                    answer.push_back(to_string(nums[index]));
                }
                else{
                    string add = to_string(nums[index]) + "->" + 
                        to_string(nums[i-1]);
                    answer.push_back(add);
                }
                index = i;
            }
        }
        if(index != nums.size()){
            if(index == nums.size() - 1){
                    answer.push_back(to_string(nums[index]));
                }
                else{
                    string add = to_string(nums[index]) + "->" + 
                        to_string(nums[nums.size()-1]);
                    answer.push_back(add);
                }
        }
        return answer;
    }
};