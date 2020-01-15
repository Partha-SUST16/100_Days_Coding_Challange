#include <bits/stdc++.h>
using namespace std;
// * Definition for singly-linked list.
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
        int sum = 0;
        ListNode *l3 = NULL;
        ListNode **node = &l3;
        while (l1 != NULL or l2 != NULL or sum > 0)
        {
            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            (*node) = new ListNode(sum % 10);
            sum /= 10;
            node = &((*node)->next);
        }
        return l3;
    }
};