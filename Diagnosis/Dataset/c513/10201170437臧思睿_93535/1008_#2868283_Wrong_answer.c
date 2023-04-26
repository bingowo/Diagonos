#include <stdio.h>
#include <string.h>
#include <math.h>
typedef long long int ll;

int main()
{
    int i,j,t=0,T;
    scanf("%d\n",&T);
    while(t++<T)
    {
        ll x,y;
        scanf("%d %d",&x,&y);
        int count=0;
        while(x||y)
        {
            if((x&1)^(y&1)==1){count++;}
            x>>=1;
            y>>=1;
        }
        printf("%d\n",count);
    }
}
