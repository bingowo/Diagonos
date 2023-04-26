#include <stdio.h>

int main()
{
    int T, n,cnt=1,max=0;
    scanf("%d",&T);
    for(int i= 0; i<T; i++)
    {
        scanf("%d",&n);
        max= 0;cnt= 1;
        if(n == 1) max= 1;
        while (n/2)
        {
            if ((n&1) != ((n>>1)&1))cnt++;
            max= ((max>cnt)? max: cnt);
            if ((n&1) == ((n>>1)&1)) cnt= 1;
            n>>=1;
        }
        printf("case #%d:\n%d\n",i,max);

    }
    return 0;

}
