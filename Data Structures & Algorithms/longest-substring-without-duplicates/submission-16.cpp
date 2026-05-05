class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0; int r = 0;
        int res = 0;
        unordered_set<int> hashset;
        while(r < s.length()){
            while(hashset.count(s[r])){
                hashset.erase(s[l]);
                l++;
            }
            hashset.insert(s[r]);
            res = max(r-l+1, res);
            r++;
        }
        return res;
    }
};
