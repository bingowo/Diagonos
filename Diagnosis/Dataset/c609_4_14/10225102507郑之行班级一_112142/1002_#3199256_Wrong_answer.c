#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        int n,cnt=0,cnt2=0;
        scanf("%d",&n);
        int n2=n>>1;
        while(n>0)
        {
            if((n&1)!=(n2&1))cnt2++;
            else cnt2=0;
            n>>=1;n2>>=1;
            if(cnt2>cnt)cnt=cnt2;
        }
        printf ("case #%d:\n%d\n",i,cnt);
    }
    return 0;
}
