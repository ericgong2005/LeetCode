#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0){
            return;
        }
        if(m == 0){
            for(int i = 0; i < n; i++){
                nums1[i] = nums2[i];
            }
            return;
        }
        int pos1 = m - 1, pos2 = n - 1;
        while(pos2 >= 0 && pos1 >= 0){
            if(nums1[pos1] > nums2[pos2]){
                nums1[pos1 + pos2 + 1] = nums1[pos1];
                pos1--;
            }
            else{
                nums1[pos1 + pos2 + 1] = nums2[pos2];
                pos2--;
            }
        }
        while(pos2 >= 0){
            nums1[pos2] = nums2[pos2];
            pos2--;
        }
        return;
    }
};