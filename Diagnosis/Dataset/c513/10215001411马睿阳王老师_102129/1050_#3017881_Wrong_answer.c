#include<stdio.h>
#include<string.h>

int main()
{
   char s1[100],s2[100],s[100];
   int i=0,j=0,k=0,t1=0,t2=0,T,l1=0,l2=0,l=0,w=0;
   scanf("%d",&T);
   for(i=0;i<T;i++)
   {
       k=0;
       int d1=0,d2=0;
       scanf("%s",s1);
       scanf("%s",s2);
       scanf("%s",s);
       l1=strlen(s1);
       l2=strlen(s2);
       l=strlen(s);
       printf("case #%d:\n",i);
       for(j=0;j<l;j++)//s
       {
           if(s[j]==s1[k]) //s1
           {
               t1=j;
               for(;k<l1;k++)
               {
                   if(s[t1+1]==s1[k+1]) t1++;
                   else break;
               }
               if(j+l1==t1)
               {
                   d1=t1-1;//s从t2到d1是s1
                   break;
               }
            }
       }
       for(j=0;j<l;j++)//s
       {
           if(s[j]==s2[k]) //s2
           {
               t2=j;
               for(;k<l2;k++)
               {
                   if(s[t2+1]==s2[k+1]) t2++;
                   else break;
               }
               if(j+l2==t2)
               {
                   d2=t2-1;//s从t1到d2是s1
                   break;
               }
            }
       }
       w=t2-d1-1;
       printf("%d\n",w);
   }
}
