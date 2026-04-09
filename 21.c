/* leetcode 21 - merge two sorted lists
 * Apr 7, 2026
 */

struct ListNode {
        int val;
        struct ListNode *next;
};

typedef struct ListNode node;

node *mergeTwoLists(node *l1, node *l2)
{
        node dummy;
        node *p = &dummy;

        while (l1 && l2) {
                node **s = l1->val < l2->val ? &l1 : &l2;
                p->next = *s;
                p = p->next;
                *s = (*s)->next;
        }

        if (l1)
                p->next = l1;
        else
                p->next = l2;

        return dummy.next;
}
