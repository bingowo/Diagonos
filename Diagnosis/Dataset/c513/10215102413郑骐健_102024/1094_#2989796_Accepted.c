#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int s[1000];
    int cnt;
    int sign;
} bigint;

bigint trans(char*p)
{
    bigint mid;
    memset(&mid,0,sizeof(mid));
    int i=strlen(p);
    while(i>1)
    {
        mid.s[strlen(p)-i] = *(p+i-1)-'0';
        i--;
    }
    if(p[0]=='-')
    {
        mid.sign=-1;
        mid.cnt = strlen(p)-1;
    }
    else
    {
        mid.s[strlen(p)-1]= *p-'0';
        mid.cnt = strlen(p);
        mid.sign=1;
    }
    return mid;
}

bigint sub(bigint a,bigint b)
{
    bigint res;
    memset(&res,0,sizeof(res));
    int i;
    int carry=0;
    int sign = a.sign*b.sign;
    if(a.sign<0)
    {
        bigint p;
        p = b;
        b = a;
        a = p;
    }
    for(i=0;i<a.cnt||i<b.cnt;i++)
    {
        int p = a.s[i]-b.s[i]*sign+carry;
        if(p<0)
        {
            p+=10;
            carry=-1;
        }
        else if(p>=10)
        {
            carry = p/10;
            p = p%10;
        }
        else carry =0;
        res.s[i] = p;
    }
    if(carry >0)
    {
        res.s[i] =carry;
    }
    int g;
    for( g =400;g>0;g--)if(res.s[g]!=0)break;
    res.cnt = g+1;
    return res;
}

int cmp(const void*p1,const void *p2)
{
    bigint a = *(bigint*)p1;
    bigint b = *(bigint*)p2;
    int i =(a.cnt>b.cnt)?a.cnt:b.cnt;
    if(a.sign > b.sign)return -1;
    else if(b.sign>a.sign)return 1;
    else if(a.sign==1&&b.sign==1)
    {
        for(;i>=0;i--)
        {
            if(a.s[i]<b.s[i])return 1;
            else if(a.s[i]>b.s[i]) return -1;
        }
    }
    else
    {
        for(;i>=0;i--)
        {
                if(a.s[i]<b.s[i])return -1;
            else if(a.s[i]>b.s[i]) return 1;
        }
    }
    return -1;

}

int main()
{
    int n;
    scanf("%d",&n);
    bigint*p = (bigint*)malloc(sizeof(bigint)*200);
    char s[300];
    for(int i = 0;i<n;i++)
    {
        scanf("%s",s);
        p[i] = trans(s);
    }
    qsort(p,n,sizeof(bigint),cmp);
    bigint res = sub(p[0],p[n-1]);
    for(int k =res.cnt-1;k>=0;k--)
        printf("%d",res.s[k]);

    return 0;
}
