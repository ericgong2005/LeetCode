#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> list;
        for(int i = 0; i < nums.size(); i++){
            list[nums[i]]++;
        }
        int answer = 0;
        int value = list.begin()->first;
        int len = 0;
        for(auto i = list.begin(); i != list.end(); i++){
            if(i->first != value + 1){
                answer = max(len, answer);
                len = 1;
            }
            else{
                len++;
            }
            value = i->first;
        }
        answer = max(len, answer);
        return answer;
    }
};