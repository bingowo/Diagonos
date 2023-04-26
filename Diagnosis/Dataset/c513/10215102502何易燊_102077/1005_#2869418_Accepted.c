#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(int a[])
{
    for (int i=159;i>=0;i--) if (a[i]!=0) return i;
    return 0;
}

int mydiv(int a[])
{
    int i = 0;
    int res = a[i];
    while (1)
    {
        a[i++] = res/8;
        res %= 8;
        res = res*10+a[i];
        if (!res&&i>check(a)) break;
    }
    return i;
}

main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        int a[160] = {0};
        char s[160] = {};
        scanf("%s",s);
        int cir = 0;
        for (int j=strlen(s)-1;j>1;j--)
        {
            a[0] += s[j]-'0';
            cir = mydiv(a);
        }
        printf("case #%d:\n0.",i);
        for (int j=1;j<cir;j++) printf("%d",a[j]);
        printf("\n");
    }
    return 0;
}