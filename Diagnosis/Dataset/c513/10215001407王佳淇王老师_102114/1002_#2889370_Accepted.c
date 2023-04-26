#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
long long poww(int x,int y)
{
    int i=y;
    long long r=1;
    for(;i>0;i--)
    {
        r*=x;
    }
    return r;
}
int main()
{
    int T,k;
    scanf("%d",&T);
    for(k=0;k<T;k++)
    {
        int fis[128],i,j;
        for(i=0;i<128;i++)
        {
            fis[i]=-1;
        }
        char chu[65];
        int len,co=1;
        scanf("%s",chu);
        char*ch=chu;
        len=strlen(chu);
       int num=0;
        long long re=0;
        for(j=0;j<len;j++,ch++)
        {
            if(fis[*ch]!=-1) continue;
            else
                {
                    if(num==1) {fis[*ch]=0;num++;}
                    else
                    {
                    fis[*ch]=co;
                    co++;
                    num++;
                    }
                }
        }
        if(num==1) num=2;
        ch=chu;
        for(j=0;j<len;j++,ch++)
        {
            re=(fis[*ch]*poww(num,len-1-j))+re;
        }
        printf("case #%d:\n%lld\n",k,re);
    }
    return 0;
}