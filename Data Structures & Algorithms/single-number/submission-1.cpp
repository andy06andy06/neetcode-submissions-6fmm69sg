class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> hashset;
        for(int num : nums){
            if(hashset.count(num)){
                hashset.erase(num);
            }
            else{
                hashset.insert(num);
            }
        }
        return *hashset.begin();
    }
};
