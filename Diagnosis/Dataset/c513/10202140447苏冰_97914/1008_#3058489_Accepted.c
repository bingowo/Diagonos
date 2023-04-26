#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int z=x^y;
        int cnt=0;
        while(z!=0)
        {
            cnt+=z&1;
            z=z>>1;
        }
        //printf("case #%d:\n",cas);
        printf("%d\n",cnt);
    }
    return 0;
}

