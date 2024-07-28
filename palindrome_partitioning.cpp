class Solution
{
public:
    bool isPalindrome(string str, int start, int end)
    {
        while (start <= end)
            if (str[start++] != str[end--])
                return false;

        return true;
    }

    void solve(int idx, string s, vector<string> &&temp, vector<vector<string>> &ans)
    {
        if (idx == s.length())
        {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < s.length(); i++)
        {
            if (isPalindrome(s, idx, i))
            {
                temp.push_back(s.substr(idx, i - idx + 1));
                solve(i + 1, s, move(temp), ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        solve(0, s, {}, ans);
        return ans;
    }
};