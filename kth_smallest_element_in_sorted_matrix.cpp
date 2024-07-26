class Solution {
public:
    int countOfSallerOrEqualElements(vector<vector<int>>& matrix, int val) {
        int n = matrix.size(), m = matrix[0].size();
        int count = 0;

        for (int i=0; i<n; i++) {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), val) - matrix[i].begin();
        }

        return count;

    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        int l = matrix[0][0], r = matrix[n-1][m-1];
        int ans = -1;

        while (l <= r) {
            int mid = l + (r-l) / 2;
            int count = countOfSallerOrEqualElements(matrix, mid);
            if (count >= k) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};

auto init_io = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();