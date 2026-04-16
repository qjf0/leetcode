/* leetcode 28 - find the index of the first occurrence in a string
 * Apr 16, 2026
 */

/* bf */
int strStr(char *heystack, char *needle)
{
	for (int i = 0; heystack[i] != '\0'; ++i) {
		int j = 0;

		while (needle[j] != '\0' && heystack[i + j] == needle[j])
			++j;

		if (needle[j] = '\0')
			return i;
	}

	return -1;
}
