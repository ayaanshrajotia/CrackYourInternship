class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto eDistance = [](const vector<int>& point) {
        return (point[0] * point[0]) + (point[1] * point[1]);
        };

        priority_queue<pair<int, int>> pq;

        for(int i=0; i<points.size(); i++) {
            pq.push({eDistance(points[i]), i});
            if (pq.size() > k) pq.pop();
        }

        vector<vector<int>> ans;

        while(!pq.empty()) {
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};