/* leetcode 83 - remove duplicates from sorted list
 * Apr 8, 2026
 */

struct ListNode {
        int val;
        struct ListNode *next;
};

typedef struct ListNode node;

node *deleteDuplicates(node *head)
{
        node **pp = &head;

        while (*pp && (*pp)->next) {
                if ((*pp)->val == (*pp)->next->val) {
                        node *dup = (*pp)->next;
                        (*pp)->next = dup->next;
                } else {
                        pp = &(*pp)->next;
                }
        }

        return head;
}
