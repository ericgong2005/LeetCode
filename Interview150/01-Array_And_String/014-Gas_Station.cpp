#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curgas = 0, mingas = INT_MAX, pos = 0;
        for(int i = 0; i < gas.size(); i++){
            curgas += gas[i] - cost[i];
            if(curgas < mingas){
                mingas = curgas;
                pos = i;
            }
        }
        if(curgas >=0){
            return (pos + 1)%gas.size();
        }
        return -1;
    }
};