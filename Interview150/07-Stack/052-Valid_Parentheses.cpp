#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,pair<int, int>> parentheses ({{'(',make_pair(0,1)},
            {')',make_pair(0,-1)},{'{',make_pair(1,1)},{'}',make_pair(1,-1)},
            {'[',make_pair(2,1)},{']',make_pair(2,-1)}});
        stack<int> track;
        for(int i = 0; i < s.size(); i++){
            if(parentheses[s[i]].second == 1){
                track.push(parentheses[s[i]].first);
            }
            else{
                if(track.size() == 0 || track.top() != parentheses[s[i]].first){
                    return false;
                }
                else{
                    track.pop();
                }
            }
        }
        return (track.size() == 0);
    }
};