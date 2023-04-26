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
        char s[200];
        int onecount=0,sum;
        gets(s);
        int len= strlen(s);
        sum=len*8;
        for(int i=0;i<len;i++)
        {
            do {
                onecount += s[i] % 2;
                s[i] /= 2;
            }while(s[i] >0);
        }
        int g=gcd(sum,onecount);
        printf("%d/%d\n",onecount/g,sum/g);
    }
    return 0;
}