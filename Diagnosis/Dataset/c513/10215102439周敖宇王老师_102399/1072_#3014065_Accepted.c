#include<stdio.h>
int r0,f;
long long aabs(long long x)
{
    if(x<0) x=-x;
    return x;
}
void path(long long x,long long y,int r,char *m)
{
    if(r!=0)
    {
        long long d=1LL<<(r-1);
        if(aabs(x)>aabs(y))
        {
            if(x>0)
            {
                path(x-d,y,r-1,m);
                m[r]='E';
            }
            else
            {
                path(x+d,y,r-1,m);
                m[r]='W';
            }
        }
        else
        {
            if(y>0)
            {
                path(x,y-d,r-1,m);
                m[r]='N';
            }
            else
            {
                path(x,y+d,r-1,m);
                m[r]='S';
            }
        }
    }
    else
    {
        if(x==0 && y==0)
        {
            printf("%d\n",r0);
            f=1;
        }
        else
            printf("-1\n");
    }
}

int main()
{
    long long x,y,t=1;
    char m[100];
    scanf("%lld%lld",&x,&y);
    r0=0;
    f=0;
    while(t<aabs(x)+aabs(y)+1)
    {
        t*=2;
        r0++;
    }
    path(x,y,r0,m);
    if(f==1)
    {
        for(int i=1;i<=r0;i++)
        printf("%c",m[i]);
    }
    return 0;
}
