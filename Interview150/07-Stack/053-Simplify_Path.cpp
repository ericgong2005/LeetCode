#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> cannon;
        int index = 0;
        for(int i = 1; i < path.size(); i++){
            if(path[i] == '/'){
                string dir = path.substr(index, i - index);
                if(dir.compare("/..") == 0){
                    if(cannon.size() != 0){
                        cannon.pop_back();
                    }
                }
                else if(dir.compare("/") != 0 && dir.compare("/.") != 0){
                    cannon.push_back(dir);
                }
                index = i;
            }
        }
        if(index != path.size() - 1){
            string dir = path.substr(index, path.size() - index);
            if(dir.compare("/..") == 0){
                if(cannon.size() != 0){
                    cannon.pop_back();
                }
            }
            else if(dir.compare("/") != 0 && dir.compare("/.") != 0){
                cannon.push_back(dir);
            }
        }
        string answer;
        for(int i = 0; i < cannon.size(); i++){
            answer += cannon[i];
        }
        if(answer.size() == 0){
            answer = "/";
        }
        return answer;
    }
};