#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{
   int t;
   scanf("%d",&t);
   char c=getchar();
   for(int i=0;i<t;i++)
   {
       char s[201];
       gets(s);
       char *p=s;
       int mapal[26]={0},index=0;
       while(*p)
       {
          if(isalpha(*p))
          {
              mapal[*p-'A']+=1;
          }
          p++;
       }
       p=s;
       for(;mapal[index]==0;index++);
       while(*p)
       {
           if(isalpha(*p))
           {
               *p=index+'A';
               mapal[index]--;
               for(;mapal[index]==0;index++);
                
           }
           p++;
       }
       printf("case #%d:\n",i);
       printf("%s\n",s);
       
   }
   return 0;
}

