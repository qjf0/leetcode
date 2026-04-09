/* leetcode 160 - intersection of two linked lists
 * Apr 8, 2026
 */

struct ListNode {
        int val;
        struct ListNode *next;
};

typedef struct ListNode node;

node *getIntersectionNode(node *ha, node *hb)
{
        node *a = ha;
        node *b = hb;

        while (a != b) {
                a = a ? a->next : hb;
                b = b ? b->next : ha;
        }

        return a;
}
