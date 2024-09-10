#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
        {
            return s;
        }
        string answer = "";
        int first, second, leap = numRows*2 - 2;
        for(int row = 0; row < numRows; row++){
            for(int pos = 0; pos + row < s.size(); pos += leap){
                answer.append(s.substr(pos + row, 1));
                if(row != 0 && leap - row > row && pos + leap - row < s.size()){
                    answer.append(s.substr(pos + leap - row,1));
                }
            }
        }
        return answer;
    }
};