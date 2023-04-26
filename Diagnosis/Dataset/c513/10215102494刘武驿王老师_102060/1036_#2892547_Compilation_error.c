#include<stdio.h>
#include<stdlib.h>
struct pos
{
  long long int x;
  long long int y;
  long long int dis;
};
int main()
{
    int n;
    scanf("%d",&n);
    struct pos poss[200];
    long long int x,y;
    for(int i=0;i<n;i++)
    {
        scanf("%lld %lld",&poss[i].x,&pos[i].y);
        x=(poss[i].x<0)?-poss[i].x:poss[i].x;
        y=(poss[i].y<0)?-poss[i].y:poss[i].y;
        poss[i].dis=x+y;
    }
    long long int step=0,dis,disx,disy;
    dis=poss[0].dis;
    if(dis%2==0)
    {
        printf("%lld\n%lld",poss[0].dis,step);
        return 0;
    }
    if(dis!=0)
    {
        int j=0;
        while(pow(2,j)<=dis) j++;
        step+=j;
    }
    for(int i=1;i<n;i++)
    {
        disx=poss[i].x-poss[i-1].x;
        if(disx<0) disx=-disx;
        disy=poss[i].y-poss[i-1].y;
        if(disy<0) disy=-disy;
        dis=disx+disy;
        if(disx<pow(2,step)||disy<pow(2,step))
        {
            printf("%lld\n%lld",poss[0].dis,step);
            return 0;
        }
        if(dis%pow(2,step)!=0)
        {
            printf("%lld\n%lld",poss[0].dis,step);
            return 0;
        }
        dis/=pow(2,step);
        if(dis!=0)
        {
        int j=0;
        while(pow(2,j)<=dis) j++;
        step+=j;
        }
    }
    
}