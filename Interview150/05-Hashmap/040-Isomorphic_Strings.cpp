#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        string temps = s;
        unordered_map<char, char> cipherst;
        for(int i = 0; i < s.size(); i++){
            cipherst.insert({{s[i], t[i]}});
        }
        for(int i = 0; i < s.size(); i++){
            temps[i] = cipherst[s[i]];
        }
        bool st = (temps.compare(t) == 0);
        unordered_map<char, char> cipherts;
        for(int i = 0; i < t.size(); i++){
            cipherts.insert({{t[i], s[i]}});
        }
        for(int i = 0; i < t.size(); i++){
            t[i] = cipherts[t[i]];
        }
        bool ts = (t.compare(s) == 0);
        return (st & ts);
    }
};