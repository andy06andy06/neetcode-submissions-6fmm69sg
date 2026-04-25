class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (vector v : matrix) {
            if (target >= v.front() && target <= v.back()) {
                int l = 0;
                int r = v.size() - 1;
                while (r >= l) {
                    int mid = l + (r - l) / 2;
                    if (target > v[mid])
                        l = mid + 1;
                    else if (target < v[mid])
                        r = mid - 1;
                    else
                        return true;
                }
            } else {
                continue;
            }
        }
        return false;
    }
};
