#include <iostream>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int l = nums1.size() - 1;
        int i = m - 1, j = n - 1;

        while (j >= 0)
        {
            if (i >= 0 && nums1[i] > nums2[j])
            {
                nums1[l--] = nums1[i--];
            }
            else
            {
                nums1[l--] = nums2[j--];
            }
        }
    }
};

// T(n) = O(n)
// S(n) = O(1)