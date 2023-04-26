#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

int main()
{
    int n;
    char a[120];
    int b[100];
    int sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        gets(a);
        int length=strlen(a);
        for(int j=0;j<length;j++)
        {
            unsigned char c=a[i];
            while(c>0)
            {
                if(c&1)
                    cnt++;
                c>>=1;
            }
        }
        int m=8*length;
        cnt=cnt/(gcd(m,cnt));
        m=m/(gcd(m,cnt));
        printf("%d/%d\n",cnt,m);
    }
    return 0;
}
