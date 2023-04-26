#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int gcd(a,b)
{
    if (b==0) return a;
    else return gcd(b,a%b);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        int j=0,cnt=0;
        char s[120];
        fgets(s,120,stdin);
        while (s[j]!='\n')
        {
            int x=s[j];
            while (x){x&=(x-1);cnt++;}
            j++;
        }
        int y=8*j;
        int a=gcd(y,cnt);
        y/=a;
        cnt/=a;
        printf("%d/%d\n",cnt,y);
    }
    return 0;
}