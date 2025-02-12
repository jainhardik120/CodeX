#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    int min;
    Node *next;

    Node(int val, int min)
    {
        this->val = val;
        this->min = min;
        this->next = nullptr;
    }
};

class MinStack
{
    Node *head;

public:
    MinStack()
    {
        head = nullptr;
    }

    void push(int val)
    {

        int min;
        if (!head)
        {
            min = val;
        }
        else
        {
            if (val < head->min)
            {
                min = val;
            }
            else
            {
                min = head->min;
            }
        }
        Node *newNode = new Node(val, min);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void pop()
    {
        Node* toBeDeleted = head;
        head = head->next;
        delete toBeDeleted;
    }

    int top()
    {
        return head->val;
    }

    int getMin()
    {
        return head->min;
    }
};

int main()
{

    return 0;
}