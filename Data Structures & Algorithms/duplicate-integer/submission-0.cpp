class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        for(int i=0; i<nums.size(); i++){
            if(!hashmap.count(nums[i])){
                hashmap[nums[i]]=1;
            }
            else
               return true;
        }
        return false;
    }
};