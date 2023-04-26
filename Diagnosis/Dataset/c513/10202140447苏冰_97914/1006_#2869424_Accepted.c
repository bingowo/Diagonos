#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
     int T;
     scanf("%d",&T);
     char s[40];
     for(int i=1;i<=T;i++)
     {
         scanf("%s",s);
         int ans=0;
         int flag=0;
         int j=0;
         char t;
         while(j<strlen(s))
         {
             if(s[j]=='-')
             {
                 t='1';
                 flag=-1;
             }
             else
             {
                 t=s[j];
                 flag=1;
             }
             ans=ans*3+flag*(t-'0');
            j++;
        }
        printf("case #%d:\n",i-1);
         printf("%d\n",ans);
     }
     return 0;
}
