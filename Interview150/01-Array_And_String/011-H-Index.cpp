#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int index = 0, i = citations.size() - 1;
        while(i >= 0){
            if (citations[i] >= index + 1){
                index++;
            }
            else{
                return index;
            }
            i--;
        }
        return index;
    }
};