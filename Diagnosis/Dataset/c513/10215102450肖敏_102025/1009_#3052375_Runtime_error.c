#include <stdio.h>
#include <string.h>
int gcd(int a,int b)
{
    return b?(gcd(b,a%b)):a;
}
int main() {
    int T;
    scanf("%d",&T);
    getchar();
    while(T--)
    {
        char s[120];
        int onecount=0,sum;
        gets(s);
        int len= strlen(s);
        sum=len*8;
        for(int i=0;i<len;i++)
        {
            while(s[i])
            {
                s[i]=s[i] & (s[i]-1);
                onecount++;
            }
        }
        int g=gcd(sum,onecount);
        printf("%d/%d\n",onecount/g,sum/g);
    }
    return 0;
}
