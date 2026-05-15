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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr) return nullptr;
        Node* res = head;
        unordered_map<Node*, Node*> hashmap;
        while(res!=nullptr){
            hashmap[res] = new Node(res->val);
            res = res->next;
        }
        res = head;
        while(res!=nullptr){
            hashmap[res]->next = hashmap[res->next];
            hashmap[res]->random = hashmap[res->random]; 
            res = res->next;
        }
        return hashmap[head];
    }
};
