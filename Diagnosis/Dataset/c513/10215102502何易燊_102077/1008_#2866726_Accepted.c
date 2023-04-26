#include <stdio.h>
#include <stdlib.h>

main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        int a,b;
        int cnt = 0;
        scanf("%d %d",&a,&b);
        do
        {
            if ((a&1)!=(b&1)) cnt++;
            a >>= 1, b >>= 1;
        } while (a>0||b>0);
        printf("%d\n",cnt);
    }
    system("pause");
    return 0;
}