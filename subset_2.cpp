class Solution
{
public:
    void solve(vector<int> &nums, int idx, vector<vector<int>> &ans, vector<int> temp)
    {
        ans.push_back(temp);

        for (int i = idx; i < nums.size(); i++)
        {
            if (i > idx && nums[i] == nums[i - 1])
                continue;
            temp.push_back(nums[i]);
            solve(nums, i + 1, ans, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        int sum = 0;
        vector<vector<int>> ans;
        vector<int> temp;

        sort(nums.begin(), nums.end());

        solve(nums, 0, ans, temp);

        return ans;
    }
};