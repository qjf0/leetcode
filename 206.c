/* leetcode 206 - reverse linked list
 * Apr 9, 2026
 */
#include <stdlib.h>

struct ListNode {
        int val;
        struct ListNode *next;
};

typedef struct ListNode node;

node *reverseList(node *head)
{
        if (!head)
                return NULL;

        node *slow = head;
        node *fast = head->next;
        slow->next = NULL;

        while (fast) {
                node *next = fast->next;
                fast->next = slow;
                slow = fast;
                fast = next;
        }

        return slow;
}

/* recursion */
node *reverseList_recursion(node *head)
{
        if (!head || !head->next)
                return head;

        node *new = reverseList_recursion(head->next);

        head->next->next = head;
        head->next = NULL;

        return new;
}
