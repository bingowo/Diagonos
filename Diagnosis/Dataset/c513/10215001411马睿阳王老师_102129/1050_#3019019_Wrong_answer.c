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

       if(l1==1)
       {
           for(j=0;j<l;j++)
           {
               if(s[j]==s1[0])
               {
                   d1=j;
                   break;
               }

           }
       }
       else
       {
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
                  if(j+l1-1==t1)
                  {
                     d1=t1;//s到d1是s1
                     break;
                  }
              }
           }
       }
       if(l2==1)
       {
           for(j=l-1;j>=0;j--)
           {
               if(s[j]==s2[0])
               {
                   t2=j;
                   break;
               }
           }
       }
       else
       {
           for(j=l-1;j>=0;j--)//s
          {
               if(s[j]==s2[l2-1]) //s2
              {
                  t2=j;
                  for(k=l2-1;k>=0;k--)
                 {
                      if(s[t2-1]==s2[k-1]) t2--;
                      else break;
                 }
                  if(j-l2+1==t2)
                 {
                      d2=t2;//s从t1到d2是s1
                      break;
                 }
              }
          }
       }
       w=t2-1-d1;
       printf("%d\n",w);
   }
}
