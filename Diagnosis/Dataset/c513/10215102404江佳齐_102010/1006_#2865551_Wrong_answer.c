#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int t;
    char s[100];
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%s",s);
        int n=strlen(s);
        int m=0;
        for(int j=0;j<n;j++)
        {
            if(s[j]=='-') s[j]=-1;
            m=m+s[j]*(pow(3,(n-1-j)));
        }
        printf("case #%d:\n",i);
        printf("%d",m);
    }
    return 0;
}
