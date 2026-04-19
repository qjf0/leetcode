/* leetcode 76 - minimum window substring
 * Apr 10, 2026
 */
#include <string.h>
#include <stdlib.h>
#include <limits.h>

char *minWindow(char *s, char *t)
{
        int need[128] = {0};

        for (int i = 0; t[i]; ++i)
                ++need[t[i]];

        int unique = 0;
        for (int i = 0; i < 128; ++i) {
                if (need[i] > 0)
                        ++unique;
        }

        int window[128] = {0};
        int l = 0;
        int r = 0;
        int valid = 0;
        int start = 0;
        int min = INT_MAX;

        while (s[r]) {
                char c = s[r];
                if (need[c]) {
                        ++window[c];
                        if (window[c] == need[c])
                                ++valid;
                }
                ++r;

                while (valid == unique) {
                        if (r - l < min) {
                                min = r - l;
                                start = l;
                        }

                        char d = s[l];

                        if (need[d]) {
                                if (window[d] == need[d])
                                        --valid;

                                --window[d];
                        }

                        ++l;
                }
        }

        if (min == INT_MAX)
                return "";

        char *result = malloc((min + 1));

        strncpy(result, s + start, min);
        result[min] = '\0';

        return result;
}
