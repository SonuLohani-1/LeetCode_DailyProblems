#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list according to leetcode
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {} // Constructor
    ListNode(int x) : val(x), next(nullptr) {} // Constructor
    ListNode(int x, ListNode *next) : val(x), next(next) {} // Constructor
};

// This is the solution of leetcode add two numbers II problem
// https://leetcode.com/problems/add-two-numbers-ii/

class Solution
{
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
        {
            stack<int> s1, s2;
            while(l1 != nullptr)
            {
                s1.push(l1->val);
                l1 = l1->next;
            }
            while(l2 != nullptr)
            {
                s2.push(l2->val);
                l2 = l2->next;
            }
            int carry = 0;
            ListNode* head = nullptr;
            while(!s1.empty() || !s2.empty() || carry)
            {
                int sum = carry;
                if(!s1.empty())
                {
                    sum += s1.top();
                    s1.pop();
                }
                if(!s2.empty())
                {
                    sum += s2.top();
                    s2.pop();
                }
                ListNode* newNode = new ListNode(sum % 10);
                newNode->next = head;
                head = newNode;
                carry = sum / 10;
            }
            return head;
        }
};

int main()
{
    return 0;
}