#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int table[30] = {1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103};
typedef struct {int a[200]; int len;} Bigint;

Bigint add(Bigint a,Bigint b)
{
    Bigint c;
    memset(c.a,0,sizeof(c.a));
    c.len = a.len>b.len?a.len:b.len;
    for (int i=0;i<c.len;i++)
    {
        c.a[i] += a.a[i]+b.a[i];
        c.a[i+1] += c.a[i]/10;
        c.a[i] %= 10;
    }
    if (c.a[c.len]) c.len++;
    return c;
}

Bigint mul(Bigint a,int b)
{
    for (int i=0;i<a.len;i++) a.a[i] *= b;
    a.len += 3;
    for (int i=0;i<a.len;i++)
    {
        a.a[i+1] += a.a[i]/10;
        a.a[i] %= 10;
    }
    while (a.a[a.len-1]==0) a.len--;
    return a;
}

int main()
{
    char s[151] = {};
    int digit[50]; int m = 0;
    scanf("%s",s);
    int temp = 0;
    for (int i=0;s[i];i++)
    {
        if (s[i]==',') digit[m++] = temp, temp = 0;
        else temp = temp*10+s[i]-'0';
    }
    digit[m++] = temp;
    Bigint base,ans;
    base.len = 1, ans.len = 0;
    memset(base.a,0,sizeof(base.a));
    memset(ans.a,0,sizeof(ans.a));
    base.a[0] = 1;
    for (int i=m-1;i>=0;i--)
    {
        ans = add(ans,mul(base,digit[i]));
        base = mul(base,table[m-i]);
    }
    for (int i=ans.len-1;i>=0;i--) printf("%d",ans.a[i]);
    printf("\n");
    return 0;
}