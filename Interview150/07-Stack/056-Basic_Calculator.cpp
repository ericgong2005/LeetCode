#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<bool> sign;
        sign.push(false);
        bool minus = false;
        bool prev = false;
        int total = 0;
        int index = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ' '){
                if(s[i] == '+'){
                    prev = false;
                }
                else if(s[i] == '-'){
                    prev = true;
                }
                else if(s[i] == '('){
                    sign.push(prev);
                    if(prev){
                        minus = !minus;
                        prev = false;
                    }
                }
                else if(s[i] == ')'){
                    if(sign.top()){
                        minus = !minus;
                    }
                    sign.pop();
                }
                else{
                    index = i;
                    while(isdigit(s[i])){i++;}
                    string num = s.substr(index, i - index);
                    if(minus^prev){
                        total -= stoi(num);
                    }
                    else{
                        total += stoi(num);
                    }
                    i--;
                }
            }
        }
        return total;
    }
};