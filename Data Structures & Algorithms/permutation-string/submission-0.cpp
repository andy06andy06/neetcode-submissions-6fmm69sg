class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;

        int window_size = s1.length();
        vector<int> freq1(26, 0);
    
        for(char c : s1){
            freq1[c - 'a']++;
        }

        for(int l = 0; l<s2.length(); l++){
            vector<int> freq2(26, 0);
            for(int r = l; r < l+window_size; r++){
                if(l+window_size>s2.length()) return false;
                freq2[s2[r]-'a']++;
            }
            if(freq2==freq1) return true;
        }
        return false;
    }
};
