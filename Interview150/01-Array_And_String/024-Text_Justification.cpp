#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int start, current, AddSpace, PadSpace, spaces;
        vector<string> answer;
        for(start = 0; start < words.size(); start = current){
            int length = words[start].size();
            for(current = start + 1; current < words.size() 
                && length + words[current].size() + 1 <= maxWidth; current++){
                length += 1 + words[current].size();
            }
            AddSpace = PadSpace = 0;
            if(start + 1 != current && current != words.size()){
                AddSpace = (maxWidth - length)/(current - start - 1);
                PadSpace = (maxWidth - length)%(current - start - 1);
            }
            string temp = words[start];
            for(int i = start + 1; i < current; i++){
                spaces = 1 + AddSpace;
                if(PadSpace){
                    spaces++;
                    PadSpace--;
                }
                temp += string(spaces, ' ');
                temp += words[i];
            }
            if(temp.size() < maxWidth){
                spaces = maxWidth - temp.size();
                temp += string(spaces, ' ');
            }
            answer.push_back(temp);
        }
        return answer;
    }
};