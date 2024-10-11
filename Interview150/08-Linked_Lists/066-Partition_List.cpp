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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessStart = new ListNode();
        ListNode* lessCurrent = lessStart;
        ListNode* greatStart = new ListNode();
        ListNode* greatCurrent = greatStart;
        while(head){
            if(head->val < x){
                lessCurrent->next = new ListNode(head->val);
                lessCurrent = lessCurrent->next;
            }
            else{
                greatCurrent->next = new ListNode(head->val);
                greatCurrent = greatCurrent->next;
            }
            head = head->next;
        }
        lessCurrent->next = greatStart->next;
        return lessStart->next;
    }
};