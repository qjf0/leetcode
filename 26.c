/* leetcode 26 - remove duplicates from sorted array
 * Apr 8, 2026
 */

int removeDuplicates(int *nums, int size)
{
        int result = 1;
        int *top = nums;

        for (int i = 1; i < size; ++i) {
                if (*top == nums[i])
                        continue;

                *(++top) = nums[i];
                ++result;
        }

        return result;
}
