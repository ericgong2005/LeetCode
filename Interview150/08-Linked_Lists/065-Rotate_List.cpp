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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || !head || !head->next){
            return head;
        }
        ListNode* current = head;
        int len = 1;
        while(current->next){
            len++;
            current = current->next;
        }
        k = len - k % len;
        if(k == len){
            return head;
        }
        current->next = head;
        current = head;
        while(k > 1){
            current = current->next;
            k--;
        }
        ListNode* answer = current->next;
        current->next = nullptr;
        return answer;
    }
};