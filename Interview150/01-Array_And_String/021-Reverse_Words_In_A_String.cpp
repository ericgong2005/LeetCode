#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string word = "";
        int index = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                if(index != i){
                    if(word != ""){
                        word = " " + word;
                    }
                    word = s.substr(index, i - index).append(word);
                }
                index = i+1;
            }
        }
        if(index < s.length()){
            if(word != ""){
                word = " " + word;
            }
            word = s.substr(index, s.length() - index).append(word);
        }
        return word;
    }
};