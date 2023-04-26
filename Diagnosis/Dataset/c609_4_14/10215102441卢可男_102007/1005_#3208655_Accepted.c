#include <stdio.h>
#include <stdlib.h>

int main()
{
   int t,j;
   scanf("%d",&t);
   for(j=0;j<t;j++)
   {
       char s[100]={0};
       scanf("%s",&s);
       int i=0,res=0,tem;
       while(s[i])
       {
           switch(s[i])
           {
               case '1':tem=1;break;
               case '0':tem=0;break;
               case '-':tem=-1;break;
               default:
                        break;

           }
           res=(res+tem)*3;
           i++;
       }
       res/=3;
        printf("case #%d:\n%d\n",j,res);
   }

}
