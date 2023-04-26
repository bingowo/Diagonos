#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a,int b) {return !b? a: gcd(b,a%b);}

int main()
{
    int n;
    scanf("%d ",&n);
    for (int i=0;i<n;i++)
    {
        int cnt = 0;
        char s[121] = {};
        gets(s);
        int tot = strlen(s);
        for (int j=0;j<tot;j++)
            for (int k=0;s[j];k++)
            {
                if (s[j]&1==1) cnt++;
                s[j] >>= 1;
            }
        int g = gcd(cnt,tot*8);
        printf("%d/%d\n",cnt/g,tot*8/g);
    }
    return 0;
}