class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minheap;
    int k_size;
    KthLargest(int k, vector<int>& nums) {
        k_size = k;
        for(int num : nums){
            minheap.push(num);
            if(minheap.size() > k_size)
                minheap.pop();
        }
    }
    
    int add(int val) {
        minheap.push(val);
        if(minheap.size() > k_size)
            minheap.pop();
        return minheap.top();
    }
};
