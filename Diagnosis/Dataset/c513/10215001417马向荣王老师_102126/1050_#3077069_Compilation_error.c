#include <stdio.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d ", &t);
    for (int z = 0; z < t; z++)
    {
        char s1[81], s2[81], s3[81];
        scanf("%s", s1);
        scanf("%s", s2);
        scanf("%s", s3);
        char* idx1 = NULL, *idx2 = NULL;
        idx1 = strstr(s3, s1);
        idx2 = strrstr(s3, s2);
        printf("case #%d:\n", z);
        if (idx1 == NULL || idx2 == NULL || idx1 == idx2)
            printf("0\n"); 
        else if (idx2 < idx1)
            printf("%d\n", strrstr(s3, s1) - strstr(s3, s2) - strlen(s2));
        else if (idx2 > idx1)
            printf("%d\n", idx2 - idx1 - strlen(s1));
    }
    return 0;
}