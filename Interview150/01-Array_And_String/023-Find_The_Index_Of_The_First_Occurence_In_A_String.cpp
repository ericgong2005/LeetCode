#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int ComputeHash(string a){
        int hash = 0;
        for(int i = 0; i < a.size(); i++){
            hash += a[i];
        }
        return hash;
    }
    int strStr(string haystack, string needle) {
        if(haystack.substr(0, needle.size()) == needle){
            return 0;
        }
        int needlehash = ComputeHash(needle);
        cout << needlehash << endl;
        int curhash = ComputeHash(haystack.substr(0, needle.size()));
        for(int i = 1; i + needle.size() <= haystack.size(); i++){
            curhash += haystack[i + needle.size() - 1] - haystack[i - 1];
            cout << i << " " << curhash <<endl;
            if(curhash == needlehash && haystack.substr(i, needle.size()) == needle){
                return i;
            }
        }
        return -1;
    }
};