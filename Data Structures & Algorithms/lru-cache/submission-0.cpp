class Node{
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr){}
};

class LRUCache {
private:
    unordered_map<int, Node*> hashmap;
    int cap;
    Node* left;
    Node* right;
    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void insert(Node* node){
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(hashmap.count(key)){
            remove(hashmap[key]);
            insert(hashmap[key]);
            return hashmap[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(hashmap.count(key)){
            remove(hashmap[key]);
        }
        Node* newnode = new Node(key, value);
        insert(newnode);
        hashmap[key] = newnode;
        if(hashmap.size() > cap){
            Node* lru = left->next;
            remove(lru);
            hashmap.erase(lru->key);
        }
    }
};
