//Problem - Remove Nth Node From End of List

// Solution

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *wantsN, *notLast;
        wantsN = notLast = head;

        while (notLast->next != NULL)
        {

            while (n > 0)
            {

                notLast = notLast->next;
                n--;

                if (notLast == NULL)
                    return head->next;
            }

            if (notLast->next == NULL)
            {
                break;
            }

            wantsN = wantsN->next;
            notLast = notLast->next;
        }

        if (notLast == wantsN)
        {
            return NULL;
        }

        wantsN->next = wantsN->next->next;

        return head;
    }
};

//Problem Statement

// Given the head of a linked list, remove the nth node from the end of the list and return its head.

// Example 1:

// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
// Example 2:

// Input: head = [1], n = 1
// Output: []
// Example 3:

// Input: head = [1,2], n = 1
// Output: [1]

// Constraints:

// The number of nodes in the list is sz.
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz

// Follow up: Could you do this in one pass?