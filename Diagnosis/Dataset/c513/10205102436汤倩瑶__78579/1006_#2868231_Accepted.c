#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
       int n=0;
       char s[100];
       scanf("%s",s);
       int l=strlen(s);
       for(int j=0;j<l;j++)
       {
           if(s[j]=='1')
           n=n*3+1;
           else if(s[j]=='-')
            n=n*3-1;
           else n=n*3;
       }
      printf("%d\n",n);
    }

}
