#include <stdlib.h>
#include <string.h>

int main()
{
   int T=0;
   scanf("%d",&T);
   char s1[]="the",s2[]="a",s3[]="an",s4[]="of",s5[]="for",s6[]="and";
   for(int i=0;i<T;i++)
   {
       getchar();
       int sum=0;
       char ch=getchar();
       while(ch!='\n');
       {
         char s[101]="";
         int i=0;
         while(ch!=' '&&ch!='\n')
         {
           s[i]=ch;
           i++;
           ch=getchar();
         }
         if(ch==' ') ch=getchar();
         s[i]=0;
         if(strlen(s)>3) ;
         else if(strcmp(s,s1)==0||strcmp(s,s2)==0||strcmp(s,s3)==0||strcmp(s,s4)==0
         ||strcmp(s,s5)==0||strcmp(s,s6)==0) sum+=1;
       }
       printf("case #%d:\n%d\n",i,sum);
   }
}
