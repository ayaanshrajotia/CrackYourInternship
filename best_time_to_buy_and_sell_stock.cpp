#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int l = 0;
        int r = 1;
        int mProfit = 0;

        while (r < prices.size())
        {
            if (prices[l] < prices[r])
            {
                int profit = prices[r] - prices[l];
                mProfit = max(mProfit, profit);
            }
            else
            {
                l = r;
            }
            r += 1;
        }

        return mProfit;
    }
};

// T(n) = O(n)
// S(n) = O(1)