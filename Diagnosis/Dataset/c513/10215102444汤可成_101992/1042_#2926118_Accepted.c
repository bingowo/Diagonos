#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void*a, const void*b)
{
    return *(char*)a - *(char*)b;
}

void comb(char* s, char* char_comb)
{
    if(*s)
    {
        char left[17] = {0};
        sprintf(left, "%s%c", char_comb, s[0]);
        printf("%s\n", left);
        comb(s+1, left);
        comb(s+1, char_comb);
    }
}

int main()
{
    int T = 0;
    int i = 0;
    scanf("%d", &T);
    for(i = 0; i<T; i++)
    {
        printf("case #%d:\n",i);
        char s[17] = {0};
        char char_comb[17] = {0};
        scanf("%s", s);
        int len = strlen(s);
        qsort(s, len, sizeof(s[0]),cmp);
        int j = 1;
        char ss[17] = {0};
        int m = 0;
        ss[0] = s[0];
        while(j<len)
        {
            if(s[j] == s[j-1])
                j++;
            else
            {
                ss[++m] = s[j++];

            }
        }
        comb(ss,char_comb);
    }
    return 0;
}
