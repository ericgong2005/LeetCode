#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        set<string> ops ({"+", "-", "*", "/"});
        for(int i = 0; i < tokens.size(); i++){
            if(ops.find(tokens[i]) == ops.end()){
                nums.push(stoi(tokens[i]));
            }
            else{
                int b = nums.top();
                nums.pop();
                int a = nums.top();
                nums.pop();
                if(tokens[i].compare("+") == 0){
                    nums.push(a + b);
                }
                else if(tokens[i].compare("-") == 0){
                    nums.push(a - b);
                }
                else if(tokens[i].compare("*") == 0){
                    nums.push(a * b);
                }
                else if(tokens[i].compare("/") == 0){
                    nums.push(a / b);
                }
            }
        }
        return nums.top();
    }
};