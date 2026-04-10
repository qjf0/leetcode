/* leetcode 86 - partition list
 *  Apr 7, 2026
 */

#include <stdlib.h>

struct ListNode {
        int val;
        struct ListNode *next;
};

typedef struct ListNode node;

node *partition(node *head, int x)
{
        node sd;
        node ld;
        node *sp = &sd;
        node *lp = &ld;
        node *cur = head;

        while (cur) {
                if (cur->val < x) {
                        sp->next = cur;
                        sp = sp->next;
                } else {
                        lp->next = cur;
                        lp = lp->next;
                }

                cur = cur->next;
        }

        sp->next = ld.next;
        lp->next = NULL;

        return sd.next;
}
