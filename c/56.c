/* leetcode 56 - length of last word
 * Apr 16, 2026
 */

int lengthOfLastWord(char *s)
{
	int l = 0;
	
	while (*s) {
		if (*s++ != ' ')
			++l;
		else if (*s && *s != ' ')
			l = 0;
	}

	return l;
}
