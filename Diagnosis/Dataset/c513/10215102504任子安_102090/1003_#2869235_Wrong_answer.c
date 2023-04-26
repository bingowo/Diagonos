#include <stdio.h>
#include <stdlib.h>

main()
{
    int a;
    scanf("%d",&a);
    for (int i=0;i<a;i++)
    {
        int n;
        scanf("%d",&n);
        int now = 1;
        int ans = 1;
        while (n>1)
        {
            while ((n&1)==((n>>1)&1)&&(n>>1)>0) n >>= 1;
            while ((n&1)!=((n>>1)&1)&&(n>>1)>0)
            {
                now++;
                n >>= 1;
            }
            if (now>ans) ans = now;
            now = 1;
        }
        printf("case #%d:\n%d\n",i,ans);
    }
    return 0;
}