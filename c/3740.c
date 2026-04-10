/* leetcode 3740 - minimum distance between three equal elements I
 * Apr 10, 2026
 */

#define ABS(x) ({ \
    __typeof__(x) _x = (x); \
    _x < 0 ? -_x : _x; \
})

int minimumDistance(int *nums, int size)
{
        if (size < 3)
                return -1;

        int map[size + 1][2];

        for (int i = 0; i <= size; ++i) {
                for (int j = 0; j < 2; ++j)
                        map[i][j] = -1;
        }

        int result = 200;

        for (int i = 0; i < size; ++i) {
                if (map[nums[i]][0] == -1) {
                        map[nums[i]][0] = i;
                } else if (map[nums[i]][1] == -1) {
                        map[nums[i]][1] = i;
                } else {
                        int len = ABS((i - map[nums[i]][0]) * 2);
                        result = result < len ? result : len;
                        map[nums[i]][0] = map[nums[i]][1];
                        map[nums[i]][1] = i;
                }
        }

	return result == 200 ? -1 : result;
}
