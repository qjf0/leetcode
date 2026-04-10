/* leetcode 876 - middle of the linked list
 * Apr 7, 2026
 */

struct ListNode {
        int val;
        struct ListNode *next;
};

typedef struct ListNode node;

node *middleNode(node *head)
{
        node *map[100];

        int p = 0;
        while(head) {
                map[p++] = head;
                head = head->next;
        }

        return map[p / 2];
}
