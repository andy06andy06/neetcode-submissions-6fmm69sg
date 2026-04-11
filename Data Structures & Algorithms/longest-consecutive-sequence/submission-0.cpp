class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashset;
        int longest = 0;
        for(int i = 0; i<nums.size(); i++){
            hashset.insert(nums[i]);
        }
        for(int num : hashset){
            if (!hashset.count(num-1)){
                int length = 1;
                while(hashset.count(num+length)){
                    length++;
                }
                longest = max(length, longest);
            }
        }
        return longest;
    }
};
