#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;i++)
    {
        char s[10000];
        scanf("%s",s);
        int j,l;
        l=strlen(s);
        double xs=(s[l-1]-48)*pow(8,-1);
        for(j=l-1;j>1;j--)
        {
            xs=(xs+s[j]-48)*pow(8,-1);
        }
        printf("case #%d:\n%lf\n",i,xs);
    }
}
