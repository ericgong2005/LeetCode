#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> Convert = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}};
        int total = 0;
        int cur = Convert[s[0]], count = 1;
        for(int i = 1; i < s.size(); i++){
            int check = Convert[s[i]];
            if(check == cur){
                count++;
            }
            else if(check < cur){
                total += cur*count;
                cur = check;
                count = 1;
            }
            else{
                total -= cur*count;
                cur = check;
                count = 1;
            }
        }
        return total + cur*count;
    }
};