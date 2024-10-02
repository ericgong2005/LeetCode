#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> words;
        for(int i = 0; i < t.size(); i++){
            words[t[i]]++;
        }
        int l = 0, r = 0, len = INT_MAX;
        string answer;
        unordered_map<char, int> temp = words;
        bool match = false;
        while(r < s.size() || match){
            if(match){
                while(words.find(s[l]) == words.end() || temp[s[l]] < 0){
                    if(words.find(s[l]) != words.end()){
                        temp[s[l]]++;
                    }
                    l++;
                }
                if(r - l < len){
                    len = r-l;
                    answer = s.substr(l, len);
                }
                if(s[l] == s[r]){
                    l++;
                    r++;
                }
                else{
                    temp[s[l]]++;
                    l++;
                    match = false;
                }
            }
            else{
                char next = s[r];
                r++;
                if(words.find(next) != words.end()){
                    temp[next]--;
                    if(temp[next] == 0){
                        match = true;
                        for(auto i = words.begin(); i != words.end(); i++){
                            if(temp[i->first] > 0){
                                match = false;
                                break;
                            }
                        }
                    }
                    else if(temp[next] < 0 && s[l] == next){
                        temp[next]++;
                        l++;
                    }
                }
            }
        }
        return answer;
    }
};