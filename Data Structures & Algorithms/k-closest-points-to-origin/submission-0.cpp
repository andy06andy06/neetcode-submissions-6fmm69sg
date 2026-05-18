class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>, vector<pair<int,vector<int>>>, greater<pair<int, vector<int>>>> minheap;
        vector<vector<int>> res;
        for(vector<int> point : points){
            int distance = point[0]*point[0] + point[1]*point[1];
            minheap.push({distance, point});
        }
        while(k>0){
            res.push_back(minheap.top().second);
            minheap.pop();
            k--;
        }
        return res;
    }
};
