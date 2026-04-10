/* leetcode 234 - palindrome linked list
 * Apr 9, 2026
 */

#include <stdbool.h>
#include <stdlib.h>

struct ListNode {
        int val;
        struct ListNode *next;
};

typedef struct ListNode node;

// #define isPalindrome_map ispalindrome
bool helper(int *arr, int n)
{
        for (int i = 0, j = n - 1; i < j; ++i, --j) {
                if (arr[i] != arr[j])
                        return 0;
        }

        return 1;
}

bool isPalindrome_map(node *head)
{
        int val[100000];
        int tail = 0;
        while (head) {
                val[tail++] = head->val;
                head = head->next;
        }

        return helper(val, tail);
}

/* O1 memory space */
bool isPalindrome(node *head)
{
        if (!head || !head->next)
                return true;

        node *slow = head;
        node *fast = head;
        while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
        }

        node *prev = NULL;
        node *curr = slow;
        while (curr) {
                node *next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
        }

        node *p1 = head;
        node *p2 = prev;
        while (p2) {
                if (p1->val != p2->val)
                        return 0;
                p1 = p1->next;
                p2 = p2->next;
        }

        return 1;
}
