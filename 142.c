/* leetcode 142 - linked list cycle ii
 * Apr 7, 2026
 */

#include <stdlib.h>

struct ListNode {
        int val;
        struct ListNode *next;
};

typedef struct ListNode node;

node *detectCycle(node *head)
{
        node *slow = head;
        node *fast = head;

        while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;

                if (fast == slow) {
                        node *ptr = head;

                        while (ptr != slow) {
                                ptr = ptr->next;
                                slow = slow->next;
                        }

                        return ptr;
                }
        }

        return NULL;
}
