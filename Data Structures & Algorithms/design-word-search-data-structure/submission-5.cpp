class TrieNode {
   public:
    unordered_map<char, TrieNode*> hashmap;
    bool isEnd = false;
};

class WordDictionary {
    TrieNode* root;

   private:
    bool dfs(string word, int index, TrieNode* cur) {
        if (index == word.length()) return cur->isEnd;

        char c = word[index];
        if (c == '.') {
            for (auto pair : cur->hashmap) {
                TrieNode* next_node = pair.second;
                if(dfs(word, index+1, next_node))
                    return true;
            }
            return false;
        }
        else {
            if(!cur->hashmap.count(c)){
                return false;
            }
            return dfs(word, index+1, cur->hashmap[c]);
        }
    }

   public:
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (!cur->hashmap.count(c)) {
                cur->hashmap[c] = new TrieNode();
            }
            cur = cur->hashmap[c];
        }
        cur->isEnd = true;
    }

    bool search(string word) {
        TrieNode* cur = root;
        return dfs(word, 0, cur);
    }
};
