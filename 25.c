/* leetcode 25 - reverse nodes in k group
 * Apr 8, 2026
 */
#include <stdlib.h>

struct ListNode {
        int val;
        struct ListNode *next;
};

typedef struct ListNode node;

node *reverseKGroup(node *head, int k)
{
        node *l[k];
        node *p = head;

        node dummy;
        node *result = &dummy;

        while (p) {
                int i = 0;
                node *ori = p;
                while (i < k) {
                        if (!p) {
                                result->next = ori;
                                goto end;
                        }

                        l[i++] = p;
                        p = p->next;
                }

                for (int j = i - 1; j >= 0; --j) {
                        result->next = l[j];
                        result = result->next;
                }

                result->next = p;
        }

end:
        return dummy.next;
}


/* Recursion */
// #define reverseKGroup_r reverseKGroup
node *reverseKGroup_r(node *head, int k)
{
        node *cur = head;
        int cnt = 0;

        while (cur && cnt < k) {
                cur = cur->next;
                ++cnt;
        }

        if (cnt < k)
                return head;

        node *prev = NULL;
        node *next = NULL;
        cur = head;

        for (int i = 0; i < k; ++i) {
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
        }

        head->next = reverseKGroup_r(cur, k);

        return prev;
}
