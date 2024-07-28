class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;

        for (int i = 0; i < s.length(); i++)
            mp[s[i]]++;

        priority_queue<pair<int, int>> pq;

        for (auto& it : mp)
            pq.push({it.second, it.first});

        string ans;

        pair<int, char> prev = {-1, '#'};
        while (!pq.empty()) {
            auto ele = pq.top();
            pq.pop();

            ans += ele.second;

            if (prev.first > 0)
                pq.push(prev);

            ele.first--;
            prev = ele;
        }

        if (ans.length() == s.length()) {
            return ans;
        } else {
            return "";
        }
    }
};