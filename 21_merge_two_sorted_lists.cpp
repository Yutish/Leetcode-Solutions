//Problem - Merge Two Sorted Lists

// Solution

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {

        ListNode *head = NULL, *curr = NULL;

        while (l1 != NULL && l2 != NULL)
        {

            if (l1->val <= l2->val)
            {

                if (head == NULL)
                    head = l1;
                else
                    curr->next = l1;

                if (l1 != NULL)
                    curr = l1;

                l1 = l1->next;
            }

            else
            {

                if (head == NULL)
                    head = l2;
                else
                    curr->next = l2;

                if (l2 != NULL)
                    curr = l2;

                l2 = l2->next;
            }
        }

        if (l1 == NULL && l2 != NULL)
        {

            if (curr == NULL)
                return l2;

            curr->next = l2;
        }

        if (l2 == NULL && l1 != NULL)
        {

            if (curr == NULL)
                return l1;

            curr->next = l1;
        }

        return head;
    }
};

//Problem Statement

// Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.

// Example 1:

// Input: l1 = [1,2,4], l2 = [1,3,4]
// Output: [1,1,2,3,4,4]
// Example 2:

// Input: l1 = [], l2 = []
// Output: []
// Example 3:

// Input: l1 = [], l2 = [0]
// Output: [0]

// Constraints:

// The number of nodes in both lists is in the range [0, 50].
// -100 <= Node.val <= 100
// Both l1 and l2 are sorted in non-decreasing order.