#include<stdio.h>
#include<math.h>
int r0;
void path(long long x,long long y,int r,char *m)
{
    if(r!=0)
    {
        long long d=1<<(r-1);
        if(abs(x)>abs(y))
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
        }
        else
            printf("-1\n");
    }
}

int main()
{
    long long x,y;
    char m[100];
    scanf("%lld%lld",&x,&y);
    r0=ceil(log2(abs(x)+abs(y)+1));
    path(x,y,r0,m);
    for(int i=0;i<=r0;i++)
        printf("%c",m[i]);
}