/* leetcode 3 - longest substring without repeating characters
 * Apr 12, 2026
 */

#include <string.h>

int lengthOfLongestSubstring(char *s)
{
        int len = strlen(s);

        if (len == 1 || !len) {
                return len;
        }

        int map[128];
        for (int i = 0; i < 128; ++i)
                map[i] = -1;

        int l = 0;
        int result = 1;

        for (int r = 0; r < len; ++r) {
                char ch = s[r];

                l = map[ch] >= l ? map[ch] + 1 : l;
                map[ch] = r;

                result = r - l + 1 > result ? r - l + 1 : result;
        }

        return result;
}
