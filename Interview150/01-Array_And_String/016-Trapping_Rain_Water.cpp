#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int lpos = 0, rpos = height.size() - 1;
        int lmax = height[0], rmax = height[rpos];
        int water = 0;
        while(lpos < rpos){
            if(lmax < rmax){
                water += lmax - height[lpos];
                lpos++;
                lmax = max(lmax, height[lpos]);
            }
            else{
                water += rmax - height[rpos];
                rpos--;
                rmax = max(rmax, height[rpos]);
            }
        }
        return water;
    }
};