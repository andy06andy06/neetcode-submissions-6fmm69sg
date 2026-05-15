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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pointer1 = head;
        ListNode* pointer2 = head;
        int list_size = 1;
        while(pointer1->next!=nullptr){
            list_size++;
            pointer1 = pointer1->next;
        }
        if(list_size==n){
            head = head->next;
        }
            
        for(int i = 1; i<list_size-n; i++){
            pointer2 = pointer2->next;
        }
        if(n==1) pointer2->next = nullptr;
        else pointer2->next = pointer2->next->next;
        return head;
    }
};
