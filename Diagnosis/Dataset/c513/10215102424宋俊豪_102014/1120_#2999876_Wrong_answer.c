#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
int main()
{
    int ans,t,x,y,r,cnt,c,n,k;
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        ans=0,cnt=0;
        printf("case #%d\n",i);
        scanf("%d%d%d%d",&r,&c,&n,&k);
        int a[11][11]= {0};
        for(int j=0; j<n; j++)
        {
            scanf("%d%d",&x,&y);
            a[x][y]=1;
        }
        for(int rl=1; rl<=r; rl++)
        {
            for(int cl=1; cl<=c; cl++)
            {
                for(int rr=1; rr<=r+1-rl; rr++)
                {
                    for(int cr=1; cr<=c+1-cl; cr++)
                    {
                        ans=0;
                        for(int r0=0; r0<rl; r0++)

                            for(int c0=0; c0<cl; c0++)
                            {
                                if(a[rr+r0][cr+c0])ans++;

                            } if(ans>=k)cnt++;


                    }
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
