#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    stack<pair<int, int>> list;

    MinStack() {
        
    }
    
    void push(int val) {
        if(list.empty()){
            list.push({val, val});
        }
        else{
            list.push({val, min(val, list.top().second)});
        }
    }
    
    void pop() {
        list.pop();
    }
    
    int top() {
        return list.top().first;
    }
    
    int getMin() {
        return list.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */