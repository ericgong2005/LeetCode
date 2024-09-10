#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lpos = 0, rpos = numbers.size() - 1, current;
        vector<int> answer;
        while(lpos < rpos){
            current = numbers[lpos] + numbers[rpos];
            if(current == target){
                answer.push_back(lpos + 1);
                answer.push_back(rpos + 1);
                return answer;
            }
            if(current > target){
                rpos--;
            }
            else{
                lpos++;
            }
        }
        return answer;
    }
};