#include <bits/stdc++.h>
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
class Solution {
public:
    int length(ListNode* head){
        int count = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode*temp = head;
       if (n == length(head)) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
       int count=0;
       while(temp->next!=nullptr && count!=length(head)-n-1){
        temp=temp->next;
        count++;
       }
       ListNode*todel = temp->next;
       temp->next = temp->next->next;
       delete(todel);
       return head;
    }
};