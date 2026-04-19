/* leetcode 66 - plus one
 * Apr 16, 2026
 */

#include <stdlib.h>

int *plusOne(int *d, int size, int *rsize)
{
	for (int i = size - 1; i >= 0; --i) {
		if (d[i] < 9) {
			++d[i];
			*rsize = size;

			return d;
		}

		d[i] = 0;
	}

	int *result = malloc((size + 1) * sizeof(int));
	result[0] = 1;
	for (int i = 1; i <= size; ++i)
		result[i] = 0;

	*rsize = size + 1;
	return result;
}
