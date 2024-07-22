class Solution
{
public:
    void solve(vector<int> &candidates, int idx, int sum, int target, vector<int> &temp, vector<vector<int>> &ans)
    {
        if (sum == target)
        {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < candidates.size(); i++)
        {
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;
            if (sum > target)
                break;
            temp.push_back(candidates[i]);
            solve(candidates, i + 1, sum + candidates[i], target, temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> temp;

        sort(candidates.begin(), candidates.end());

        solve(candidates, 0, 0, target, temp, ans);

        return ans;
    }
};