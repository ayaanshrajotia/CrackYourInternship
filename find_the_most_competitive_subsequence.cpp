class Solution
{
public:
    vector<int> mostCompetitive(vector<int> &nums, int k)
    {
        vector<int> st;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            while (!st.empty() && st.back() > nums[i] && st.size() + (nums.size() - i - 1) >= k)
            {
                st.pop_back();
            }
            st.push_back(nums[i]);
            if (st.size() == k)
                ans = st;
        }

        return ans;
    }
};