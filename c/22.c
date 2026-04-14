/* leetcode 14 - generate parentheses
 * Apr 14, 2026
 */

#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

void backtrack(int l, int r, int pos, int n,
        char *buf, char **result, int *cnt)
{
        if (pos == 2 * n) {
                result[*cnt] = malloc((2 * n + 1) * sizeof(char));
                strcpy(result[*cnt], buf);
                ++(*cnt);
                return;
        }

        if (l < n) {
                buf[pos] = '(';
                backtrack(l + 1, r, pos + 1, n, buf, result, cnt);
        }

        if (r < l) {
                buf[pos] = ')';
                backtrack(l, r + 1, pos + 1, n, buf, result, cnt);
        }
}

char **generateParenthesis(int n, int *rsize)
{
        int max_size = 1;

        for (int i = n + 1; i <= 2 * n; ++i) {
                max_size = max_size * i / (2 * n - i + 1);
        }

        char **result = malloc(max_size * sizeof(char *));


        char *buf = malloc((2 * n + 1) * sizeof(char));
        buf[2 * n] = '\0';

        int cnt = 0;
        backtrack(0, 0, 0, n, buf, result, &cnt);

        *rsize = cnt;
        return result;
}
