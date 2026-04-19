/* leetcode 141 - linked list cycle
 * Apr 7, 2026
 */
#include <stdbool.h>

struct ListNode {
        int val;
        struct ListNode *next;
};

typedef struct ListNode node;

bool hasCycle(node *head)
{
        if (!head)
                return false;

        node *a = head;
        node *b = head->next;

        while (a && b) {
                a = a->next;
                b = b->next;
                if (!b)
                        return false;
                else
                        b = b->next;

                if (a == b)
                        return true;
        }

        return false;
}
