#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string, string>> sorted;
        for(int i = 0; i < strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            sorted.push_back(make_pair(temp, strs[i]));
        }

        unordered_map<string, vector<string>> group;
        for(int i = 0; i < sorted.size(); i++){
            group[sorted[i].first].push_back(sorted[i].second);
        }

        vector<vector<string>> answer;
        for(auto i = group.begin(); i != group.end(); i++){
            answer.push_back(i->second);
        }
        return answer;
    }
};