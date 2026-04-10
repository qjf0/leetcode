/* leetcode 5 - longest palindromic substring
 * Apr 9, 2026
 */

#include <string.h>
#include <stdlib.h>

char *longestPalindrome(char *s)
{
        int n = strlen(s);
        if (n < 2)
                return s;

        int start = 0;
        int max = 1;

        for (int i = 0; i < n; ++i) {
                int l = i;
                int r = i;
                while (l >= 0 && r < n && s[l] == s[r]) {
                        if (r - l + 1 > max) {
                                start = l;
                                max = r - l + 1;
                        }
                        --l;
                        ++r;
                }

                l = i;
                r = i + 1;
                while (l >= 0 && r < n && s[l] == s[r]) {
                        if (r - l + 1 > max) {
                                start = l;
                                max = r - l + 1;
                        }

                        --l;
                        ++r;
                }
        }

        char *sub = malloc(max + 1);
        strncpy(sub, s + start, max);
        sub[max] = '\0';

        return sub;
}
