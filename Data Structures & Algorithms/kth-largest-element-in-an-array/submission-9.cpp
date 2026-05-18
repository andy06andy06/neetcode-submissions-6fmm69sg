class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minheap;
        int res;
        for(int num : nums){
            if(minheap.size()!=0 && minheap.size()>=k && num<=minheap.top()) continue;
            minheap.push(num);
            if(minheap.size()>k){
                minheap.pop();
            }
        }
        return minheap.top();
    }
};
