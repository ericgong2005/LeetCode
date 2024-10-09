#include <iostream>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return nullptr;
        }
        Node* temp;
        Node* answer;
        Node* savehead = head;
        answer = temp = new Node(head->val);
        unordered_map<Node*, Node*> random;
        random.insert({{head, answer}});
        head = head->next;
        while(head){
            temp->next = new Node(head->val);
            random.insert({{head, temp->next}});
            head = head->next;
            temp = temp->next;
        }
        head = savehead;
        temp = answer;
        while(head){
            if(head->random){
                temp->random = random[head->random];
            }
            head = head->next;
            temp = temp->next;
        }
        return answer;
    }
};