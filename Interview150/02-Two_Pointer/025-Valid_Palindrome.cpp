#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isAlpha(char a){
        return ((a > 64 && a < 91) || (a > 96 && a < 123));
    }
    bool isMatch(char a, char b){
        return (a == b || (isAlpha(a) && isAlpha(b) && (a - b == 32 || b - a == 32)));
    }
    bool isPalindrome(string s) {
        int lpos = 0, rpos = s.size() - 1;
        while(lpos < rpos){
            while(!(isAlpha(s[lpos]) || (s[lpos] > 47 && s[lpos] < 58))){
                lpos++;
                if(lpos >= rpos){
                    return true;
                }
            }
            while(!(isAlpha(s[rpos]) || (s[rpos] > 47 && s[rpos] < 58))){
                rpos--;
                if(lpos >= rpos){
                    return true;
                }
            }
            if(!isMatch(s[lpos], s[rpos])){
                cout << s[lpos] << " " << s[rpos];
                return false;
            }
            lpos++;
            rpos--;
        }
        return true;
    }
};