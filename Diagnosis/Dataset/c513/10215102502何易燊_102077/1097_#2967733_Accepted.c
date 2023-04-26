#include <stdio.h>

int main()
{
    char s[81] = {};
    while (scanf("%s",s)!=EOF)
    {
        char set[165][82] = {};
        int p = 82, upper = 82, bottom = 82;
        int rec[165] = {};
        set[p][1] = s[0]; rec[p] = 1;
        for (int i=1;s[i];i++)
        {
            if (s[i]>s[i-1]) p--;
            else if (s[i]<s[i-1]) p++;
            rec[p] = i+1;
            set[p][i+1] = s[i];
            if (p<upper) upper = p;
            if (p>bottom) bottom = p;
        }
        for (int i=upper;i<=bottom;i++)
        {
            for (int j=1;j<=rec[i];j++) printf("%c",!set[i][j]?' ':set[i][j]);
            printf("\n");
        }
    }
    return 0;
}