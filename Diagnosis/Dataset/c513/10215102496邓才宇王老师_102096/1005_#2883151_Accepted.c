#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
   int T;
   scanf("%d",&T);
   for(int i=0;i<T;i++)
   {
       char s[50];
       scanf("%s",s);
       char s1[150];
       int numbers=0;
        int len=strlen(s)-1;
        int d,j,t;
for (; len != 1; --len)
{
    d= s[len]-'0';
    j = 0;
    do {
        if (j<numbers)
            t=d*10+s1[j]-'0';
        else
            t=d*10;
        s1[j++] =t/8+'0';
        d=t%8;
    } while (d!=0||j<numbers);
    numbers=j;
}
s1[numbers]='\0';
printf("case #%d:\n0.%s\n",i,s1);
}
}
