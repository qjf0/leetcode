/* leetcode #1 - two sum
 * Apr 19, 2026
 */

#include <stdlib.h>

/*
 * A hash map would make this problem a lot easier,
 * but since C doesn't have a built-in hash table and implementing one from
 * scratch is too much trouble, I decided to go with qsort + two pointers.
 */

typedef struct item {
        int val;
        int idx;
} item;

int *build(int a, int b)
{
        int *p = malloc(sizeof(int) * 2);
        p[0] = a;
        p[1] = b;
        return p;
}

int compare(const void *a, const void *b)
{
        return ((item *)a)->val - ((item *)b)->val;
}

int *twoSum(int *nums, int size, int tar, int *rsize)
{
        *rsize = 2;
        if (size == 2)
                return build(0, 1);

        item map[size];
        for (int i = 0; i < size; ++i) {
               map[i].idx = i;
               map[i].val = nums[i];
        }

        qsort(map, size, sizeof(item), compare);

        int l = 0;
        int r = size - 1;

        while (l < r) {
                int sum = map[l].val + map[r].val;

                if (sum > tar)
                        --r;
                else if (sum < tar)
                        ++l;
                else
                        return build(map[l].idx, map[r].idx);
        }

        return NULL;
}
