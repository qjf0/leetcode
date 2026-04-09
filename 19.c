/* leetcode 19 - remove nth node from end of list
 * Apr 8, 2026
 */

struct ListNode {
        int val;
        struct ListNode *next;
};

typedef struct ListNode node;

node *removeNthFromEnd(node *head, int n)
{
        node dummy = {0, head};
        node *fast = &dummy;
        node *slow = &dummy;

        for (int i = 0; i <= n; i++)
                fast = fast->next;

        while (fast) {
                fast = fast->next;
                slow = slow->next;
        }

        node *d = slow->next;
        slow->next = d->next;

        return dummy.next;
}
