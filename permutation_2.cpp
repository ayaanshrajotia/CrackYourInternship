class Solution
{
public:
    void solve(vector<int> nums, int index, vector<vector<int>> &ans)
    {
        // base case
        if (index >= nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for (int j = index; j < nums.size(); j++)
        {
            if (j != index && nums[index] == nums[j])
                continue;
            swap(nums[index], nums[j]);
            solve(nums, index + 1, ans);
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int index = 0;
        sort(nums.begin(), nums.end());

        solve(nums, index, ans);

        return ans;
    }
};