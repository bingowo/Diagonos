#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



typedef struct {
    int s[1200];
    int len;
}bigint;

bigint init(int x)
{
    bigint a;
    memset(a.s,0,sizeof(a.s));
    a.len=1;
    a.s[0] = x;
    return a;
}

bigint mul(bigint a,bigint b)
{
    bigint res;
    memset(res.s,0,sizeof(res.s));
    res.len = a.len+b.len;
    int i,j;
    for( i=0;i<a.len;i++)
    {
        int carry =0;
    for( j =0;j<b.len;j++)
    {
        int p1 = res.s[i+j]+a.s[i]*b.s[j]+carry;
        if(p1>=10)
        {
            carry = p1/10;
        }
        else carry = 0;
        res.s[i+j] = p1%10;
    }
    while(carry>0)
    {
        int n =i+j;
        int p1 = res.s[n]+carry;
        if(p1>=10)carry =p1/10;
        else carry =0;
        res.s[n++] = p1%10;
    }
    }
    if(res.s[res.len-1]==0)
        res.len-=1;
    return res;
}

int judge (char *s)
{
    int n =1;
    if((*s)!=*(s-1))
    {
        n++;
        if(*(s+1)!=*(s-1)&&*(s)!=*(s+1))n++;
    }
    else
    {
        if(*s!=*(s+1))n++;
    }
    return n;
}
int main()

{
    char s[600];
    scanf("%s",s);
    if (strlen(s)==1)
    {
        printf("1");
        return 0;
    }
    int n1 =1;
    int n2 =1;
    if(s[0]!=s[1])n1++;
    if(s[strlen(s)-1]!=s[strlen(s)-2])n2++;
    bigint res = init(n1);
    res = mul(init(n2),res);
    for(int i = 1;i<strlen(s)-1;i++)
    {
    res = mul(init(judge(&s[i])),res);
    }
    for(int k = res.len -1;k>=0;k--)
    {
        printf("%d",res.s[k]);
    }
    return 0;
}
