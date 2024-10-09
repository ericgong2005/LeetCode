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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answer = l1;
        int carry = 0;
        while(l1->next && l2->next){
            l1->val += l2->val + carry;
            carry = l1->val/10;
            l1->val = l1->val%10;
            l1 = l1->next;
            l2 = l2->next;
        }
        l1->val += l2->val + carry;
        carry = l1->val/10;
        l1->val = l1->val%10;
        if(!l1->next && l2->next){
            l1->next = l2->next;
            l2->next = nullptr;
        }
        if(l1->next && !l2->next){
            l1 = l1->next;
            while(l1->next && carry){
                l1->val += carry;
                carry = l1->val/10;
                l1->val = l1->val%10;
                l1 = l1->next;
            }
            l1->val += carry;
            carry = l1->val/10;
            l1->val = l1->val%10;
        }
        if(!l1->next && !l2->next && carry){
            l1->next = new ListNode(1);
        }

        return answer;
    }
};