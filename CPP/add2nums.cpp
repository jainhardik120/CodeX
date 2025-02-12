#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = NULL;
        ListNode *curr;
        int carry = 0;
        while (l1 || l2)
        {
            int a, b;
            if (l1)
            {
                a = l1->val;
                l1 = l1->next;
            }
            else
            {
                a = 0;
            }
            if (l2)
            {
                b = l2->val;
                l2 = l2->next;
            }
            else
            {
                b = 0;
            }
            int sum = a + b + carry;
            cout << sum << " ";
            carry = sum / 10;
            if (!head)
            {
                head = new ListNode(sum % 10);
                curr = head;
            }
            else
            {
                curr->next = new ListNode(sum % 10);
                curr = curr->next;
            }
        }
        if (carry != 0)
        {
            curr->next = new ListNode(carry);
        }
        return head;
    }
};

int main()
{
    Solution sol;
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    ListNode *sum = sol.addTwoNumbers(l1, l2);
    while (sum)
    {
        cout << sum->val << " ";
        sum = sum->next;
    }
    return 0;
}