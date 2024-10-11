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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* end = head;
        ListNode* last;
        int count = 0;
        while(count < k && end){
            last = end;
            end = end->next;
            count++;
        }
        if(count < k){
            return head;
        }
        ListNode* current = head;
        if(end){
            end = reverseKGroup(end, k);
        }
        ListNode* answer = end;
        while(current != last){
            ListNode* temp = current->next;
            current->next = answer;
            answer = current;
            current = temp;
        }
        current->next = answer;
        return current;
    }
};