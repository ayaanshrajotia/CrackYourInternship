#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++)
        {
            int more = target - nums[i];

            if (m.find(more) != m.end())
            {
                return {m[more], i};
            }

            m[nums[i]] = i;
        }

        return {-1, -1};
    }
};

// T(n) = O(n)
// S(n) = O(n)