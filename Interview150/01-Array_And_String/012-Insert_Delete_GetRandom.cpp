#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class RandomizedSet {
public:
    unordered_map<int, int> ToIndex;
    vector<int> Store;
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(ToIndex.find(val) == ToIndex.end()){
            ToIndex.insert({val, Store.size()});
            Store.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(ToIndex.find(val) == ToIndex.end()){
            return false;
        }
        int index = ToIndex[val];
        int temp = Store[Store.size() - 1];
        ToIndex[temp] = index;
        Store[index] = temp;
        ToIndex.erase(val);
        Store.pop_back();
        return true;
    }
    
    int getRandom() {
        return Store[rand()%Store.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */