#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> answer;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= end){
                end = max(intervals[i][1], end);
            }
            else{
                answer.push_back(vector<int> ({start, end}));
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        answer.push_back(vector<int> ({start, end}));
        return answer;
    }
};