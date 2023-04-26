#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int T,i,j,k,n,t,l;
    double a,b;
    char s[100];
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%s",s);
        l=strlen(s);
        printf("case #%d:\n0.",i);
        a=0;
        k=0;
        for(j=2;j<l;j++)
        {
            a=a+(s[j]-'0')*pow(8,1-j);
        }
        while(a>0)
        {
            a=a*10;
            t=a;
            a=a-t;
            printf("%d",t);
        }
        printf("\n");
    }
    return 0;
}