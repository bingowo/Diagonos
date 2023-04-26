#include <stdio.h>
#include <string.h>
int num_of_one(char *s);
int GCD(int a,int b);
int main()
{
    int n,a,b,d;
    char s[1000];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",s);
        a=num_of_one(s);
        b=8*strlen(s);
        d=GCD(a,b);
        // printf("%d %d %d",a,b,d);
        a=a/d;b=b/d;
        printf("%d/%d\n",a,b);
    }
}
int num_of_one(char *s)
{
    int ans=0;
    char *p,c;
    p=s;
    while(*p)
    {
        c=*p;
        while(c!=0)
        {
            if(c&1) ans++;
            c=c>>1;
        }
        p++;
    }
    return ans;
}
int GCD(int a,int b)
{
    for(;a>0;a--)
    {
        if((b%a)==0)    return a;
    }
}
