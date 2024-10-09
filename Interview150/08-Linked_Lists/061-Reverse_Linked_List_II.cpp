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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right || !head->next){
            return head;
        }
        ListNode* answer = new ListNode(0);
        ListNode* temp = answer;
        ListNode* lnode;
        ListNode* rnode;
        ListNode* mnode;
        int index = 1;
        while(head){
            if(index < left){
                temp->next = new ListNode(head->val);
                temp = temp->next;
            }
            else if(index == left){
                lnode = new ListNode(head->val);
                rnode = lnode;
            }
            else if(index <= right){
                ListNode* add = new ListNode(head->val); 
                add->next = rnode;
                rnode = add;
            }
            else{
                break;
            }
            head = head->next;
            index++;
        }
        temp->next = rnode;
        lnode->next = head;
        return answer->next;
    }
};