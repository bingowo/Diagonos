#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

typedef struct
{
    int r[600];
    int neg;
    int cnt;
}bigint ;

bigint trans(char*p)
{
    bigint res;
    memset(&res,0,sizeof(bigint));
    int len =strlen(p);
    for(int i =strlen(p)-1;i>=0;i--)
    {
        res.r[len-i-1] = p[i]-'0';
    }
    res.cnt = len;
    res.neg = 1;
    return res;
}
bigint sub(bigint p1,bigint p2)
{
    bigint res;
    memset(&res,0,sizeof(bigint));
    int po=(p1.cnt<p2.cnt)?p2.cnt-1:p1.cnt-1;
    while(p1.r[po]==p2.r[po])po--;
    int *a;
    int*b;
    int ac;
    int bc;
    if(p2.r[po]>p1.r[po])res.neg = -1;
    else res.neg = 1;
    a = (res.neg==-1)?p2.r:p1.r;
    b = (res.neg==-1)?p1.r:p2.r;
    ac = (res.neg==-1)?p2.cnt:p1.cnt;
    bc = (res.neg==-1)?p1.cnt:p2.cnt;
    int carry = 0;
    for(int i=0;i<ac||i<bc;i++)
    {
        int p =a[i]-b[i]+carry;
        if(p<0)
        {
            p+=10;
            carry = -1;
        }
        else carry = 0;
        res.r[i] = p;
    }
    res.cnt = ac;
    while(res.r[res.cnt-1]==0&&res.cnt>1)res.cnt--;
    return res;
}

int main()
{
   char a[600];
   char b[600];
   scanf("%s%s",&a,&b);
   bigint p1,p2;
   p1=trans(a);
   p2 = trans(b);
   bigint res;
   res = sub(p1,p2);
   if(res.neg==-1)printf("-");
   for(int i =res.cnt-1;i>=0;i--)printf("%d",res.r[i]);
   return 0;
}
