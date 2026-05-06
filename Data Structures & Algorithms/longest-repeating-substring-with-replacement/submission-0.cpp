class Solution {
   public:
    int characterReplacement(string s, int k) {
        int res = 0;
        unordered_set<char> hashset(s.begin(), s.end());
        for (char c : hashset) {
            int l = 0;
            int count = 0;
            for (int r = 0; r < s.length(); r++) {
                if(s[r]==c){
                    count++;
                }
                while ((r - l + 1) - count > k){
                    if(s[l]==c){
                        count--;
                    }
                    l++;
                }
                res = max(res, r-l+1);
            }
        }
        return res;
    }
};
