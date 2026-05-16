class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> hashset;
        for(int i : nums){
            if(!hashset.count(i)){
                hashset.insert(i);
            }
            else return i;
        }
    }
};
