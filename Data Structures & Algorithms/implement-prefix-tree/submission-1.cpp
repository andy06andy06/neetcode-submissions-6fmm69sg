class TrieNode {
public:
    unordered_map<char, TrieNode*> hashmap;
    bool isEnd = false;
};

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(char c : word){
            if(!cur->hashmap.count(c)){
                cur->hashmap[c] = new TrieNode();
            }
            cur = cur->hashmap[c];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for(char c : word){
            if(!cur->hashmap.count(c)) return false;
            cur = cur->hashmap[c];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(char c : prefix){
            if(!cur->hashmap.count(c)) return false;
            cur = cur->hashmap[c];
        }
        return true;
    }
};
