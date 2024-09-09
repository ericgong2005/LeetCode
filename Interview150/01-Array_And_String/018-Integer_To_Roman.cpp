#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> Convert = {{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"},
            {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"}, {400, "CD"}, 
            {500, "D"}, {900, "CM"}, {1000, "M"}};
        int Order[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string answer = "";
        for(int i = 0; i < 13; i++){
            while(num >= Order[i]){
                answer.append(Convert[Order[i]]);
                num -= Order[i];
            }
        }
        return answer;
    }
};