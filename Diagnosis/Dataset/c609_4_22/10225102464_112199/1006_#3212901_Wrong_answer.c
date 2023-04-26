#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main()
{
    int n=0;
    scanf("%d",&n);
    int result[11]={0};
    for(int i=0;i<n;i++)
    {
        char s[66];
        scanf("%s",s);
        int a[10000];
        for(int j=0;j<10000;j++) a[j]=-1;
        int ast=0;
        char *p=s;
        a[*p]=1;
        while(*++p)
        {
            if(a[*p]==-1)
            {
                a[*p]=ast;
                ast=ast?ast+1:2;
            }
        }
        if(ast<2) ast=2;
        long long asn=0;
        p=s;
        while(*p)asn=asn*ast+a[*p++];
        result[i]=asn;
    }
    for(int i=0;i<n;i++)
    {
        printf("case #%d:\n%d\n",i,result[i]);
    }
    return 0;
}
