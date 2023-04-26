#include <stdio.h>

int main()
{   int i,T;
     for(scanf("%d",&T),i=0;i<T;i++)
     {    char s[30];       int r,j;
           printf("case #%d:\n",i);
           for  (scanf("%s",s),r=j=0;s[j];j++)  r=r*3+(s[j]=='-'? -1:(s[j]=='0'?0:1));
           printf("%d\n", r);
     }

    return 0;
}