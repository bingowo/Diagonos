#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
     char a[16][100000];
     a[0][0]='0';
     int n;
     scanf("%d",&n);
     int i,j;
     for(i=1;i<=n;i++)
     {
         strcpy(a[i],a[i-1]);
         for(j=0;j<strlen(a[i-1]);j++)
         {
             if(a[i-1][j]=='0') a[i-1][j]='1';
             else a[i-1][j]='0';
         }
         strcat(a[i],a[i-1]);
     }
     printf("%s",a[n]);
}