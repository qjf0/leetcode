/* leetcode 24 - swap nodes in pairs
 * Apr 9, 2026
 */

#include <stdlib.h>

struct ListNode {
        int val;
        struct ListNode *next;
};

typedef struct ListNode node;

node *swapPairs(node *head)
{
        if(!head || !head->next)
                return head;

        node *first = head;
        node *second = head->next;

        first->next = swapPairs(second->next);
        second->next = first;

        return second;
}
