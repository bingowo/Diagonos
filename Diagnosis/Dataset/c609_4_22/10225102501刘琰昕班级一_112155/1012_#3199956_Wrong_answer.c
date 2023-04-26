#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s[50];double ans=0,p0=1;
        scanf("%s",s);
        char *p=s+2;
        while(*p)
        {
            ans+=(*p-'0')*pow(0.125,p0);
            p++;p0++;
        }
        printf("case #%d:\n%0.100g\n",i,ans);
    }
}
