#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
    int n;
    scanf("%d",&n);
    for (int p=0;p<n;p++)
    {
        char s[1000];
        scanf("%s",s);
        int l = strlen(s);
        int mul = 1;
        int ans = 0;
        for (int i=l-1;i>=0;i--)
        {
            if (s[i]=='0') ;
            else if (s[i]=='1') ans += mul;
            else ans -= mul;
            mul *= 3;
        }
        printf("case #%d:\n%d\n",p,ans);
    }
    system("pause");
    return 0;
}