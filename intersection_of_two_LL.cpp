#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
            return headA;

        ListNode *tempA = headA;
        ListNode *tempB = headB;

        while (tempA != tempB)
        {
            tempA = tempA == NULL ? headB : tempA->next;
            tempB = tempB == NULL ? headA : tempB->next;
        }

        return tempA;
    }
};

// T(n) = O(n)
// S(n) = O(1)