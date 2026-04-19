/* leetcode 20 - valid parentheses
 * Apr 14, 2026
 */

#include <stdbool.h>

bool isValid(char *s)
{
        char st[10002];
        int top = 0;

        while (*s != '\0') {
                if (*s == '(' || *s == '{' || *s == '[') {
                        st[top++] = *(s++);
                } else {
                        if (top - 1 < 0 ||
                                (st[top - 1] != *s - 2 &&
                                st[top - 1] != *s - 1)
                        )
                                return false;
                        else
                                --top;

                        ++s;
                }
        }

        return top == 0;
}
