/* leetcode 15 - 3sum
 * Apr 13, 2026
 */

#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int **threeSum(int *nums, int size, int *r_size, int **r_col_size)
{
	qsort(nums, size, sizeof(int), cmp);

	int **res = malloc(sizeof(int *) * size * size);
	*r_col_size = malloc(sizeof(int) * size * size);
	*r_size = 0;

	for (int i = 0; i < size - 2; ++i) {
		if (i > 0 && nums[i] == nums[i - 1])
			continue;
		int l = i + 1;
		int r = size - 1;

		while (l < r) {
			int sum = nums[i] + nums[l] + nums[r];
			if (sum < 0) {
				++l;
			} else if (sum > 0) {
				r--;
			} else {
				res[*r_size] = malloc(3 * sizeof(int));
				res[*r_size][0] = nums[i];
				res[*r_size][1] = nums[l];
				res[*r_size][2] = nums[r];
				(*r_col_size)[*r_size] = 3;
				++(*r_size);

				while (l < r && nums[l] == nums[l + 1])
					++l;

				while (l < r && nums[r] == nums[r - 1])
					--r;
				++l;
				--r;
			}
		}
	}

	return res;
}

