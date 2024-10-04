#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<vector<int>> answer;
        sort(points.begin(), points.end());
        answer.push_back(points[0]);
        for(int i = 1; i < points.size(); i++){
            if(points[i][0] <= answer[answer.size() - 1][1]){
                answer[answer.size() - 1][0] = 
                    max(answer[answer.size() - 1][0], points[i][0]);
                answer[answer.size() - 1][1] = 
                    min(answer[answer.size() - 1][1], points[i][1]);
            }
            else{
                answer.push_back(points[i]);
            }
        }
        return answer.size();
    }
};