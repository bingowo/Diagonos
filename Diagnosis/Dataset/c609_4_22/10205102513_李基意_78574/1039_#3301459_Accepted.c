#include <stdio.h>
#include <string.h>

char *strrstr(const char *s1, const char *s2);

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

char *strrstr(const char *s1, const char *s2)
{
    char *tmp = strstr(s1, s2);
    char *ret = NULL;
    while (1)
    {
        if (tmp != NULL)
        {
            ret = tmp;
        }
        else
            break;
        tmp = strstr(tmp + strlen(s2), s2);
    }
    return ret;
}