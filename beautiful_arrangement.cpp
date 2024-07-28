class Solution {
public:
    int count = 0;
    void solve(vector<int>& arr, int j) {
        if (j == arr.size()) 
            count++;

        for (int i=j; i<arr.size(); i++) {
            swap(arr[i], arr[j]);
            if ((arr[j] % (j+1) == 0) || ((j+1) % arr[j] == 0)) {
                solve(arr, j+1);
            }
            swap(arr[i], arr[j]);
        }
    }
    int countArrangement(int n) {
        vector<int> arr(n, 0);
        for (int i=0; i<n; i++) arr[i] = i+1;
        solve(arr, 0);
        return count;
    }
};