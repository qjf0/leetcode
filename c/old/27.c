/* leetcode 27 - remove element
 * Apr 8, 2026
 */

int removeElement(int *nums, int size, int val)
{
        int *slow = nums;

        for (int *fast = nums; fast < nums + size; fast++) {
                if (*fast != val) {
                        *slow++ = *fast;
                }
        }

        return slow - nums;
}
