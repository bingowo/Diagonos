#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int table[30] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103};

main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        char s[100] = {};
        scanf("%s",s);
        int j;
        int a[30] = {}, b[30] = {}, c[30] = {};
        int x = 0, y = 0, z = 0;
        int num = 0, mul = 1;
        for (j=strlen(s)-1;j>=0;j--)
        {
            if (s[j]==',') {a[x++] = num; num = 0; mul = 1; continue;}
            num += (s[j]-'0')*mul;
            mul *= 10;
        }
        a[x++] = num, num = 0, mul = 1;
        memset(s,0,sizeof(s));
        scanf("%s",s);
        for (j=strlen(s)-1;j>=0;j--)
        {
            if (s[j]==',') {b[y++] = num; num = 0; mul = 1; continue;}
            num += (s[j]-'0')*mul;
            mul *= 10;
        }
        b[y++] = num, num = 0, mul = 1;
        int max = (x>y)?x-1:y-1;
        for (int k=0;k<=max+1;k++)
        {
            c[k] += a[k]+b[k];
            c[k+1] += c[k]/table[k];
            c[k] %= table[k];
        }
        printf("case #%d:\n",i);
        if (c[max+1]!=0) printf("%d,",c[max+1]);
        for (int k=max;k>=1;k--) printf("%d,",c[k]);
        printf("%d",c[0]);
        printf("\n");
    }
    return 0;

}