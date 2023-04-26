#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int r,c,n,k,x,y,j,x1,y1,x2,y2;
        int s[15][15];
        memset(s,0,sizeof(s));
        scanf("%d %d %d %d",&r,&c,&n,&k);
        for(j=0;j<n;j++)
        {
            scanf("%d %d",&x,&y);
            for(x1=x;x1<=r;x1++)
                for(y1=y;y1<=c;y1++)
                    s[x1][y1]++;
        }
        int s1=0;
        for(x1=1;x1<=r;x1++)
            for(y1=1;y1<=c;y1++)
                for(x2=x1;x2<=r;x2++)
                    for(y2=y1;y2<=c;y2++)
                        if(s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]>=k)
                            s1++;
        printf("case #%d:\n%d\n",i,s1);
    }
    return 0;
}
