/* leetcode 283 - move zeroes
 * Apr 8, 2026
 */


void moveZeroes(int *nums, int size)
{
        int cnt = 0;
        int *top = nums;

        for (int i = 0; i < size; ++i) {
                if (nums[i] == 0) {
                        ++cnt;
                        continue;
                }
                *(top++) = nums[i];
        }

        for (int i = 0; i < cnt; ++i)
                *(top + i) = 0;
}
