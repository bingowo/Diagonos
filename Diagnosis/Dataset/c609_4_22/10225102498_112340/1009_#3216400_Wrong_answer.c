#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int GCD(int m,int n)
{
    int big,small;
    int max=1;
    int i;
    if(m>=n) big=m,small=n;
    else big=n,small=m;
    for(i=1;i<=small;i++)
    {
        if(small%i==0&&big%i==0) max=i;
    }
    return max;
}

int main()
{
    int n, i;
    unsigned int p;
    char m;
    char s[125];
    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        m = getchar();
        int k = 0;
        scanf("%[^\n]",s);
        //s[k] = '\0';
        //printf("%s\n",s);
        int t = 0;
        int len = strlen(s);
        //printf("%d\n",len);
        for(k=0; k<len; k++)
        {
            p = s[k];
            while(p != 0)
            {
                p &= p - 1;
                t++;
            }
        }
        len *= 8;
        int gd = GCD(t,len);
        t /= gd;
        len /= gd;
        printf("%d/%d\n", t, len);
    }

    return 0;
}
