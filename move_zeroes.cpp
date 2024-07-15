#include <iostream>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int i = 0;

        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] != 0)
            {
                swap(nums[j], nums[i]);
                i++;
            }
        }
    }
};

// T(n) = O(n)
// S(n) = O(1)