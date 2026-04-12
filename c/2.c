/* leetcode 2 - add two numbers
 * Apr 12, 2026
 */

#include <stdlib.h>

struct ListNode {
        int val;
        struct ListNode *next;
};

typedef struct ListNode node;

node *addTwoNumbers(node *l1, node *l2)
{
        node dummy;
        node *tail = &dummy;

        int flag = 0;
        while (l1 && l2 || flag) {
                int sum = flag;

                if (l1) {
                        sum += l1->val;
                        l1 = l1->next;
                }

                if (l2) {
                        sum += l2->val;
                        l2 = l2->next;
                }

                flag = sum / 10;
                sum = sum % 10;

                node *new = malloc(sizeof(node));
                new->val = sum;
                new->next = NULL;

                tail->next = new;
                tail = new;
        }

        return dummy.next;
}
