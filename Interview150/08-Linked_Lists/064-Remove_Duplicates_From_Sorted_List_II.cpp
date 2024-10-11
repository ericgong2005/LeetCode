#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;     
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head){
            return nullptr;
        }
        if(!head->next){
            return head;
        }
        ListNode* answer = new ListNode();
        ListNode* save = answer;
        ListNode* current = head;
        bool prev = false;
        while(current->next){
            if(current->val != current->next->val){
                if(prev){
                    prev = false;
                }
                else{
                    save->next = new ListNode(current->val);
                    save = save->next;
                }
            }
            else{
                prev = true;
            }
            current = current->next;
        }
        if(!prev){
            save->next = current;
        }
        return answer->next;
    }
};