/* leetcode 92 - reverse linked list ii
 * Apr 9, 2026
 */

#include <stdlib.h>

struct ListNode {
        int val;
        struct ListNode *next;
};

typedef struct ListNode node;

node *reverseBetween(node *head, int left, int right)
{
        if (!head || left == right)
                return head;

        node dummy;
        dummy.next = head;

        node *prev = &dummy;
        for (int i = 1; i < left; ++i)
                prev = prev->next;

        node *curr = prev->next;
        node *next = NULL;

        for (int i = 0; i < right - left; ++i) {
                next = curr->next;
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
        }

        node *new = dummy.next;
        return new;
}
