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
    void reorderList(ListNode* head) {
        ListNode* l1 = head; 
        ListNode* l2 = head->next;
        while(l2 && l2->next){
            l1 = l1->next;
            l2 = l2->next->next;
        }
        ListNode* second = l1->next;
        ListNode* last = l1->next = nullptr;
        while(second){
            ListNode* temp = second->next;
            second->next = last;
            last = second;
            second = temp;
        }
        ListNode* l = head;
        ListNode* r = last;
        while(r){
            ListNode* temp1 = l->next;
            ListNode* temp2 = r->next;
            l->next = r;
            r->next = temp1;
            l = temp1;
            r = temp2;
        }
    }
};
