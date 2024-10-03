#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<char> patternlist;
        vector<string> slist;
        for(int i = 0; i < pattern.size(); i++){
            patternlist.push_back(pattern[i]);
        }
        int index = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                slist.push_back(s.substr(index, i - index));
                index = i + 1;
            }
        }
        slist.push_back(s.substr(index, s.size() - index));

        if(patternlist.size() != slist.size()){
            return false;
        }

        unordered_map<char, string> cipherptos;
        unordered_map<string, char> cipherstop;
        for(int i = 0; i < slist.size(); i++){
            cipherptos.insert({{patternlist[i], slist[i]}});
            cipherstop.insert({{slist[i], patternlist[i]}});
        }

        vector<string> testptos;
        vector<char> teststop;
        for(int i = 0; i < slist.size(); i++){
            testptos.push_back(cipherptos[patternlist[i]]);
            teststop.push_back(cipherstop[slist[i]]);
        }
        
        return((testptos == slist)&(teststop == patternlist));

    }
};