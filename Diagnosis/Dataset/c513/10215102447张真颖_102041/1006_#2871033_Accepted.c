#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 1000000000

char s[M];
long int f(char s[])
{
    long int sum=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]=='-') sum=sum*3-1;
        else sum=sum*3+s[i]-'0';
    }
    return sum;
}

int main()
{
   int T;
   scanf("%d",&T);
   for(int i=0;i<T;i++)
   {

       scanf("%s",s);
       printf("case #%d:\n",i);
       printf("%ld\n",f(s));
   }
    return 0;
}
