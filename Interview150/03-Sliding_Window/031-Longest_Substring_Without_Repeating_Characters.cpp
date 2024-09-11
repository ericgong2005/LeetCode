#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> count;
        int maxlength = 0, start = 0, cur = 0;
        while(cur < s.size()){
            cout << count[s[cur]] << endl;
            count[s[cur]]++;
            while(count[s[cur]] > 1){
                count[s[start]]--;
                start++;
            }
            maxlength = max(maxlength, cur - start + 1);
            cur++;
        }
        return maxlength;
    }
};