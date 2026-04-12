/* leetcode 1 - two sum
 * Apr 12, 2026
 */

#include <stdlib.h>

struct item {
        int v;
        int i;
};

int cmp(const void *a, const void *b)
{
        return ((struct item *)a)->v - ((struct item *)b)->v;
}

int *twoSum(int *n, int s, int t, int *rsz)
{
        *rsz = 2;

        struct item *a = malloc(sizeof(struct item) * s);
        for (int i = 0; i < s; ++i) {
                a[i].v = n[i];
                a[i].i = i;
        }

        qsort(a, s, sizeof(struct item), cmp);

        int l = 0;
        int r = s - 1;

        while (l < r) {
                int sum = a[l].v + a[r].v;

                if (sum > t) {
                        --r;
                } else if (sum < t) {
                        ++l;
                } else {
                        int *rt = malloc(sizeof(int) * 2);
                        rt[0] = a[l].i;
                        rt[1] = a[r].i;

                        return rt;
                }
        }

        return NULL;
}
