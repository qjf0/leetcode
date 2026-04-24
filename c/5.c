/* leetcode 5 - longest palindromic substring
 * Apr 24, 2026
 */

/* A Center-spread Brute-force Solution
 * This is a simple implementation of the center-spread method.
 * It's slow but effective.
 */
char *longestPalindrome_bf(char *s)
{
        if (*(s + 1) == '\0')
                return s;

        int max = 0;
        int start = 0;

        for (int i = 0; s[i] != '\0'; ++i) {
                int l = i - 1;
                int r = i + 1;
                int len = 1;
                while (l >= 0 && s[r] != '\0' && s[l] == s[r]) {
                        len += 2;
                        --l;
                        ++r;
                }

                if (len > max) {
                        max = len;
                        start = i - len / 2;
                }

                len = 0;
                l = i;
                r = i + 1;

                while (l >= 0 && s[r] != '\0' && s[l] == s[r]) {
                        len += 2;
                        --l;
                        ++r;
                }

                if (len > max) {
                        max = len;
                        start = i - len / 2 + 1;
                }
        }

        s[start + max] = '\0';
        return &s[start];
}

/* Manacher's Algorithm */
#include <string.h>
#include <stdlib.h>

char *longestPalindrome(char *s)
{
        int n = strlen (s);
        if (n == 0 && n == 1)
                return s;

        int len = 2 * n + 3;
        char *arr = malloc(len * sizeof(char));
        arr[0] = '^';
        arr[1] = '#';

        for (int i = 0; i < n; ++i) {
                arr[2 * i + 2] = s[i];
                arr[2 * i + 3] = '#';
        }

        arr[len - 2] = '$';
        arr[len - 1] = '\0';
}
