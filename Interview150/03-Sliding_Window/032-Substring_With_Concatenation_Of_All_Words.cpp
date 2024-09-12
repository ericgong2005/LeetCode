#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> target;
        int word_size = words[0].size();
        for(int i = 0; i < words.size(); i++){
            target[words[i]]++;
        }
        vector<int> answer;
        for(int i = 0; i < word_size; i++){
            unordered_map<string, int> slide;
            int size = 0;
            for(int j = i; j + word_size <= s.size(); j += word_size){
                string next = s.substr(j, word_size);
                cout << next << endl;
                if(target.find(next) == target.end()){
                    slide.clear();
                    size = 0;
                    continue;
                }
                cout << next << endl;
                slide[next]++;
                size++;
                while(slide[next] > target[next]){
                    string out = s.substr(j - word_size*(size - 1), word_size);
                    slide[out]--;
                    size--;
                }
                if(size == words.size()){
                    answer.push_back(j - word_size*(size - 1));
                }
            }
        }
        return answer;
    }
};