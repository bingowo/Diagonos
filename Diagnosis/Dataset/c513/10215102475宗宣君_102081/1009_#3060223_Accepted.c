#include <stdio.h>
#include <string.h>
int gcd(int a,int b)
{
    int m = (a>b)?a:b,n = (a>b)?b:a;
    if(n==0) return m;
    else return gcd(n,m%n);

}
int main()
{
    int n,i;
    scanf("%d",&n);
    getchar();
    for(i = 0;i<n;i++)
    {
        char s[121];
        gets(s);
        int on = 0,under,j,k;
        for(j = 0;j<strlen(s);j++)
        {
            for(k = 0;k<8;k++)
            {
                if(s[j]&(1<<k)) on++;
            }
        }
        under = strlen(s)*8;
        int num = gcd(on,under);
        printf("%d/%d\n",on/num,under/num);
    }
    return 0;
}
