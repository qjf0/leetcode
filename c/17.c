/* leetcode 17 - letter combinations of phone numbers
 * Apr 13, 2026
 */

#include <stdlib.h>
#include <string.h>

void backtrack(char *digits, int pos, int len, char *path,
                char **result, int *idx, char **map)
{
        if (pos == len) {
                result[(*idx)++] = strdup(path);
                return;
        }

        char *letters = map[digits[pos] - '0'];
        for (int i = 0; letters[i]; ++i) {
                path[pos] = letters[i];
                backtrack(digits, pos + 1, len, path, result, idx, map);
        }
}

char **letterCombinations(char *digits, int *rsize)
{
        char *map[] = {
                {},
                {},
                {"abc"},
                {"def"},
                {"ghi"},
                {"jkl"},
                {"mno"},
                {"pqrs"}, // 7
                {"tuv"},
                {"wxyz"}  // 9
        };

        *rsize = 1;
        int len = 0;
        for (char *p = digits; *p != '\0'; ++p) {
                ++len;
                if (*p == '7' || *p == '9')
                        *rsize *= 4;
                else
                        *rsize *= 3;
        }

        char **result = malloc(sizeof(char *) * *rsize);
        char *path = malloc((len + 1));
        path[len] = '\0';

        int idx = 0;
        backtrack(digits, 0, len, path, result, &idx, map);

        free(path);
        return result;
}
