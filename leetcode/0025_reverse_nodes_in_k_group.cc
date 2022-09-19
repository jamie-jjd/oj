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
  ListNode* reverseKGroup (ListNode *head, int k)
  {
    ListNode *first {head};
    ListNode *last {};
    ListNode *rfirst {head};
    ListNode *rlast {};
    ListNode *prev {};
    ListNode *node {};
    ListNode *next {};
    while (rfirst)
    {
      int m {};
      while (rfirst && ++m != k)
      {
        rfirst = rfirst->next;
      }
      if (rfirst)
      {
        last = rfirst->next;
        prev = rlast;
        node = first;
        while (node != last)
        {
          next = node->next;
          node->next = prev;
          prev = node;
          node = next;
        }
        if (rlast == nullptr)
        {
          head = rfirst;
        }
        else
        {
          rlast->next = rfirst;
        }
        rlast = first;
        rfirst = first = rlast->next = last;
      }
    }
    return head;
  }
};
