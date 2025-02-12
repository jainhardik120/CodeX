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

class Compare
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = NULL;
        ListNode *curr = head;
        priority_queue<ListNode *, vector<ListNode *>, Compare> q;
        for (auto i : lists)
        {
            q.push(i);
        }
        while (!q.empty())
        {
            ListNode* top = q.top();
            q.pop();
            if(top->next){
                q.push(top->next);
            }
            if (!curr)
            {
                curr = top;
            }else{
                curr->next = top;
                curr = curr->next;
            }
        }
        return head;
    }
};

int main()
{

    return 0;
}