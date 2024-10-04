#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> answer;
        bool added = false;
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i][1] < newInterval[0]){
                answer.push_back(intervals[i]);
            }
            else if(intervals[i][0] > newInterval[1]){
                if(!added){
                    answer.push_back(newInterval);
                    added = true;
                }
                answer.push_back(intervals[i]);
            }
            else{
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
                added = false;
            }
        }
        if(!added){
            answer.push_back(newInterval);
        }
        return answer;
    }
};