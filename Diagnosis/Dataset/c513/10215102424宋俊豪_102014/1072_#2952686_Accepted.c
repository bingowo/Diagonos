#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
typedef long long ll;
int id=0;
char s[200];
int slo(long long x,long long y,int time)
{
    if(x%2!=0)
    {
        ll E=x-1;
        ll W=x+1;
        E/=2;
        W/=2;
        y/=2;
        if(y==0&&E==0)
        {
            time++;
            s[id++]='E';
            return time;
        }
        else if(y==0&&W==0)
        {
            time++;
            s[id++]='W';
            return time;
        }
        if((E+y)%2!=0)
        {
            time++;
            s[id++]='E';
            slo(E,y,time);
        }
        else if((W+y)%2!=0)
        {
            time++;
            s[id++]='W';
            slo(W,y,time);
        }

    }
    else if(y%2!=0)
    {
        ll N=y-1;
        ll S=y+1;
        S/=2;
        N/=2;
        x/=2;
        if(x==0&&S==0)
        {
            time++;
            s[id++]='S';
            return time ;
        }
        else if(x==0&&N==0)
        {
            time++;
            s[id++]='N';
            return time;
        }
        if((x+N)%2!=0)
        {
            time++;
            s[id++]='N';
            slo(x,N,time);
        }
        else if((S+x)%2!=0)
        {
            time++;
            s[id++]='S';
            slo(x,S,time);
        }

    }
}

int main()
{   int time;
    long long x,y;
    scanf("%lld %lld",&x,&y);
    if(x==0&&y==0)
        printf("0");
    else if((x+y)%2==0)
    {
        printf("-1");
    }
    else
    {
        time=slo(x,y,0);
        printf("%d\n",time);
        printf("%s",s);
    }
    return 0;
}
