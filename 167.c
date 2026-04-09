/* leetcode 167 - two sum ii input array is sorted
 * Apr 8, 2026
 */

#include <stdlib.h>

int *twoSum(int *n, int size, int target, int *rsize)
{
        *rsize = 2;

        int l = 0;
        int r = size - 1;

        while (l < r) {
                if (n[l] + n[r] == target) {
                        int *result = malloc(sizeof(int) * 2);
                        result[0] = l + 1;
                        result[1] = r + 1;

                        return result;
                }

                if (n[l] + n[r] < target)
                        ++l;
                else
                        --r;
        }

        return NULL;
}
