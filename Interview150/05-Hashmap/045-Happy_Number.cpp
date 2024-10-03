#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> track;
        while(true){
            int num = 0;
            while(n > 0){
                num += (n%10)*(n%10);
                n = n / 10;
            }
            if(num == 1){
                return true;
            }
            track[num]++;
            if(track[num] > 1){
                return false;
            }
            n = num;
        }
    }
};