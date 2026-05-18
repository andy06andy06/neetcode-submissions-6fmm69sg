class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxheap;
        int res;
        for(int num : nums){
            maxheap.push(num);
        }
        while(k>0){
            if(k==1) return maxheap.top();
            maxheap.pop();
            k--;
        }
        return res;
    }
};
