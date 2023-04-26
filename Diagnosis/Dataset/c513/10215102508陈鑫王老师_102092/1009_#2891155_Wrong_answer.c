#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long int gcd(long long int x,long long int y)
{
    long long int c,ans;
    if(x<y)
    {
        c=x;
        x=y;
        y=c;
    }
    ans=x%y;
    while(ans)
    {
        x=y;
        y=ans;
        ans=x%y;
    }
    return y;

}
long long int num1(char n)
{
    long long int a,ans=0;
    a=n;
    while(a)
    {
        if(a&1)ans=ans+1;
        a=a>>1;
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        char a[121];
        gets(a);
        int len;
        long long int x=0,y=0,c,x1,y1;
        len=strlen(a);
        for(int j=0;j<len;j++)
        {
            x=x+num1(a[j]);
            y=y+8;
        }
        c=gcd(x,y);
        x1=x/c;
        y1=y/c;
        printf("case #%d:\n",i);
        printf("%lld/%lld\n",x1,y1);


    }
    return 0;
}
