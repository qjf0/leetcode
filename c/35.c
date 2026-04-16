/* leetcode 35 - search insert position
 * Apr 16, 2025
 */

int searchInsert(int *nums, int size, int target)
{
	int i = 0;
	while (i < size) {
		if (target <= nums[i++])
			return i - 1;
	}

	return i;
}
