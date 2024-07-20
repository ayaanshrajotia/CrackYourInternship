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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *node1 = l1;
        ListNode *node2 = l2;

        stack<int> st1, st2;
        while (node1)
        {
            st1.push(node1->val);
            node1 = node1->next;
        }
        while (node2)
        {
            st2.push(node2->val);
            node2 = node2->next;
        }

        ListNode *dummy = NULL;
        int carry = 0;
        while (!st1.empty() || !st2.empty() || carry != 0)
        {
            int sum = 0;

            if (!st1.empty())
            {
                sum += st1.top();
                st1.pop();
            }
            if (!st2.empty())
            {
                sum += st2.top();
                st2.pop();
            }

            sum += carry;
            carry = sum / 10;
            ListNode *newNode = new ListNode(sum % 10);
            newNode->next = dummy;
            dummy = newNode;
        }

        return dummy;
    }
};

// T(n) = O(n)
// S(n) = O(2n)