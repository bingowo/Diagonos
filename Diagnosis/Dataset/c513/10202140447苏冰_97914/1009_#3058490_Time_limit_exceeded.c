#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int gcd(int a,int b)
{
    if(b==0)return a;
    else return gcd(b,a%b);
}
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int cas=0;cas<n;cas++)
    {
        char s[130];
        gets(s);
        int cnt=0;
        for(int i=0;i<strlen(s);i++)
        {
            int x=(int)s[i];
            while(x!=0)
            {
                if(x&1) cnt++;
                x=x>>1;
            }
        }
        int fz=cnt;
        int fm=strlen(s)*8;
        int com=gcd(fz,fm);
        fz/=com;
        fm/=com;
        printf("%d/%d\n",fz,fm);
    }
    return 0;
}

