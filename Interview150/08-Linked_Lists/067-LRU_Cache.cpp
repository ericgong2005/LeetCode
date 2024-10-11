#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    vector<int> cache;
    unordered_map<int, int> pairs;
    int max = 0;

    LRUCache(int capacity) {
        max = capacity;
    }
    
    int get(int key) {
       if(pairs.find(key) == pairs.end()){
            return -1;
        }
        cache.erase(find(cache.begin(), cache.end(), key));
        cache.push_back(key);
        return pairs[key];
    }
    
    void put(int key, int value) {
        if(pairs.find(key) == pairs.end()){
            cache.push_back(key);
            pairs[key] = value;
            if(cache.size() > max){
                pairs.erase(pairs.find(cache[0]));
                cache.erase(cache.begin());
            }
        }
        else{
            cache.erase(find(cache.begin(), cache.end(), key));
            cache.push_back(key);
            pairs[key] = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */