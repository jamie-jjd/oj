/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
  ListNode* swapPairs (ListNode *head)
  {
    if (head)
    {
      ListNode *prev {};
      ListNode *node {head};
      ListNode *next {};
      while (node && node->next)
      {
        next = node->next;
        node->next = next->next;
        next->next = node;
        if (prev)
        {
          prev->next = next;
        }
        else
        {
          head = next;
        }
        prev = node;
        node = node->next;
      }
    }
    return head;
  }
};
