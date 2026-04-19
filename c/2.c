/* leetcode #2 - add two numbers
 * Apr 19, 2026
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
        int carry = 0;

        while (l1 || l2 || carry) {
                int sum = carry;

                if (l1) {
                        sum += l1 -> val;
                        l1 = l1->next;
                }

                if (l2) {
                        sum += l2->val;
                        l2 = l2->next;
                }

                carry = sum / 10;

                node *new = malloc(sizeof(node));
                new->val = sum % 10;
                new->next = NULL;

                tail->next = new;
                tail = new;
        }

        return dummy.next;
}
