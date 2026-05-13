/* leetcode / 1 / May 14, 2026
 * two sum
 *
 * Since there's no built-in hash table in C
 * and it's a bit of a hassle to build one from scratch,
 * I went with a simple two-pointer method.
 */

#include <stdlib.h>

struct item {
	int val;
	int i;    // original index
};

/* comparator for qsort to sort items by val */
int compare(const void *a, const void *b)
{
	return ((struct item *)a)->val - ((struct item *)b)->val;
}

int *twoSum(int *n, int size, int t, int *rsize)
{
	*rsize = 2;

	// create an array of structs to store values with their original indices
	struct item *a = malloc(sizeof(struct item) * size);
	for (int i = 0; i < size; ++i) {
		a[i].val = n[i];
		a[i].i = i;
	}

	// sort the array to enable two-pointer approach
	qsort(a, size, sizeof(struct item), compare);

	int l = 0;
	int r = size - 1;
	while (l < r) {
		int sum = a[l].val + a[r].val;

		if (sum > t) {
			--r;
		} else if (sum < t) {
			++l;
		} else {
		        // target found
			int *rt = malloc(sizeof(int) * 2);
			rt[0] = a[l].i;
			rt[1] = a[r].i;

			return rt;
		}
	}

	return NULL;
}
