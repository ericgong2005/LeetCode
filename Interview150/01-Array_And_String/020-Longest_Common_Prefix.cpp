#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1){
            return strs[0];
        }
        int i;
        for(i = 0; i < strs[0].size() ; i++){
            char check = strs[0][i];
            for(int j = 1; j < strs.size(); j++){
                if(strs[j].size() <= i || strs[j][i] != check){
                    return strs[0].substr(0, i);
                }
            }
        }
        return (i == 0) ? "" : strs[0];
    }
};