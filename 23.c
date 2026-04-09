/* leetcode 23 - merge k sorted lists
 * Apr 8, 2026
 */
#include <stdlib.h>

struct ListNode {
        int val;
        struct ListNode *next;
};

typedef struct ListNode node;

node *merge(node *l1, node *l2)
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

/* brute force */
node *mergeKLists_bf(node **lists, int size)
{
        node *result = NULL;

        for (int i = 0; i < size; ++i)
                result = merge(result, lists[i]);

        return result;
}

/* Devide & Conquer */
node *mergeKLists(node **l, int size)
{
        if (size == 0)
                return NULL;

        if (size == 1)
                return l[0];

        int mid = size / 2;
        node *left = mergeKLists(l, mid);
        node *right = mergeKLists(l + mid, size - mid);

        return merge(left, right);
}
