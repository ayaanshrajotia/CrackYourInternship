#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

// T(n) = O(n)
// S(n) = O(1)