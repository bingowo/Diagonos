#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[25];

unsigned long long tran(unsigned long long x)
{

    char mid;
    memset(s,0,sizeof(char)*25);
    int i=0;
    if(x==0) s[i++]='0';
    while(x>0)
    {
        s[i++]=(x%10)+'0';
        x/=10;
    }
    int len=i,len2=len/2,j;
    for(i=0;i<len2;i++)
    {
        mid=s[i];
        s[i]=s[len-i-1];
        s[len-i-1]=mid;
    }
    for(i=0;i<len;i++)
    {
        if(s[i]=='9')
        {
            for(j=i;j<len;j++)
            {
                s[j]='8';
            }
            break;
        }
    }
    unsigned long long re=0;
    for(i=0;i<len;i++)
    {
        re*=10;
        re+=(s[i]-'0');
    }
    //printf("x=%llu,s=%s\n",x,s);
    return re;
}

unsigned long long miao(unsigned long long x)
{
    unsigned long long co=0,bei,j,re;
    int i,len=strlen(s);
    for(i=0;i<len;i++)
    {
        co*=9;
        co+=(s[i]-'0');
    }
    bei=(co+1)/9;

    if((co%9)!=0)
    {
        for(j=0;j<(co%9);j++,x--)
        {

            if((x%9)==0) {bei++;}
        }
    }
    //printf("co=%llu,bei=%llu\n",co,bei);
    re=co-bei;
    return re;

}

int main()
{
    unsigned long long a,b,i,co=0;
    scanf("%llu%llu",&a,&b);
    unsigned long long bb,aa,rea,reb,re;
    bb=tran(b);
    reb=miao(bb);
    //printf("bb=%llu,reb=%llu\n",bb,reb);
    aa=tran(a-1);
    rea=miao(aa);
    //printf("aa=%llu,rea=%llu\n",aa,rea);
    re=reb-rea;
    printf("%llu\n",re);
    return 0;
}
