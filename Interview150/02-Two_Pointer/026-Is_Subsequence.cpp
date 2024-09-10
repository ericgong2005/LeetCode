#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int spos = 0, tpos = 0;
        while(tpos < t.size() && spos < s.size()){
            if(s[spos] == t[tpos]){
                spos++;
            }
            tpos++;
        }
        return(spos == s.size());
    }
};