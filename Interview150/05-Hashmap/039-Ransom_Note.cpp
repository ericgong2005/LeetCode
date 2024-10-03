#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> note;
        unordered_map<char, int> text;
        for(int i = 0; i < ransomNote.size(); i++){
            note[ransomNote[i]]++;
        }
        for(int i = 0; i < magazine.size(); i++){
            text[magazine[i]]++;
        }
        for(auto i = note.begin(); i != note.end(); i++){
            if(i->second > text[i->first]){
                return false;
            }
        }
        return true;
    }
};