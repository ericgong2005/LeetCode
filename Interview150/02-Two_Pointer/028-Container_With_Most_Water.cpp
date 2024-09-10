#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int lpos = 0, rpos = height.size() - 1, MaxWater = 0;
        while(lpos < rpos){
            MaxWater = max(MaxWater, min(height[lpos], height[rpos]) * (rpos - lpos));
            if(height[lpos] < height[rpos]){
                lpos++;
            }
            else{
                rpos--;
            }
        }
        return MaxWater;
    }
};