#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char way[100];
int m;
long long leiji[65];
long long danbu[65];

long long jdz(long long x)
{
    if(x>=0) return x;
    else return -x;
}

long long bushu(long long x,long long y)
{
    long long re;
    re=jdz(x)+jdz(y);
    return re;
}

long long mindis(long long x,long long y)
{
    long long len=bushu(x,y);
    if(len==0) return 0;
    else if((len%2)==0) return -1;
    else
    {
        long long b=1,i;
        for(i=1;;i++)
        {
            if(leiji[i]>=len) return i;
        }
    }
}


void lujing(long long x,long long y,long long re)
{
    if(jdz(x)>jdz(y))
    {
        if(x>0)
        {
            x-=danbu[re];
            re--;
            way[m--]='E';
        }
        else if(x<0)
        {
            x+=danbu[re];
            re--;
            way[m--]='W';
        }
    }
    else if(jdz(y)>jdz(x))
    {
        if(y>0)
        {
            y-=danbu[re];
            re--;
            way[m--]='N';
        }
        else if(y<0)
        {
            y+=danbu[re];
            re--;
            way[m--]='S';
        }
    }
    //printf("test:way[%d]=%c\n",m+1,way[m+1]);
    if(m<0) return;
    else lujing(x,y,re);
}


int main()
{
    long long x,y;
    int i,j;
    scanf("%lld%lld",&x,&y);
    memset(way,0,sizeof(char)*100);
    danbu[1]=1;
    leiji[1]=1;
    for(i=2;i<65;i++)
    {
        danbu[i]=(long long)2*danbu[i-1];
    }
    for(i=2;i<65;i++)
    {
        leiji[i]=(long long)danbu[i-1]*2+leiji[i-1];
        //printf("test: leiji[%lld]=%lld\n",i,leiji[i]);
    }
    long long re=mindis(x,y);
    //printf("test:re=%lld\n",re);
    if(re==-1) printf("-1");
    else if(re==0) printf("0");
    else
    {
        m=re-1;
       lujing(x,y,re);
       printf("%lld\n%s",re,way);
    }
    return 0;


}
