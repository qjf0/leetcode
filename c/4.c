/* leetcode 4 - mmedian of two sorted arrays
 * Apr 20, 2026
 */

/* stupid but it works */
double findMedianSortedArrays(int *n1, int size1, int *n2, int size2)
{
        int total = size1 + size2;
        int merged[total];

        int i = 0;
        int j = 0;
        int k = 0;

        while (i < size1 && j < size2) {
                if (n1[i] < n2[j])
                        merged[k++] = n1[i++];
                else
                        merged[k++] = n2[j++];
        }

        while (i < size1)
                merged[k++] = n1[i++];
        while (j < size2)
                merged[k++] = n2[j++];

        if (total % 2 == 1)
                return merged[total / 2];
        else
                return (merged[total / 2 - 1] + merged[total / 2]) / 2.0;
}


/* binary search */
