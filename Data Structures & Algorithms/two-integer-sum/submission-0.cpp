class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        int difference;
        for(int i=0; i<nums.size(); i++){
            hashmap[nums[i]] = i;
        }
        for(int i=0; i<nums.size(); i++){
            difference = target - nums[i];
            if(hashmap.count(difference) && hashmap[difference] != i)
                return {i, hashmap[difference]};
        }
      
    }
};
