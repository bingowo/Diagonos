#include <stdio.h>
#include <stdlib.h>

main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        char s[1000] = {};
        scanf("%s",s);
        int a[130];
        for (int j=0;j<130;j++) a[j] = -1;
        int len = 0;
        a[s[len]] = 1;
        while (s[len+1]==s[len]) len++;
        a[s[len+1]] = 0;
        int p = 2;
        int ans = 0;
        for (int j=len+1;s[j];j++)
        {
            len++;
            if (a[s[j]]==-1) a[s[j]] = p++;
        }
        int mul = 1;
        for (int j=len;j>=0;j--)
        {
            ans += a[s[j]]*mul;
            mul *= p;
        }
        printf("%d\n",ans);
    }
    system("pause");
    return 0;
}