#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int prev = 0, length = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                prev = (length == 0) ? prev : length;
                length = 0;
            }
            else{
                length++;
            }
        }
        return (length == 0) ? prev : length;
    }
};