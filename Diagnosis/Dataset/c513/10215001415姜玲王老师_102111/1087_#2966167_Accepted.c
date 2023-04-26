#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int Add(char*a,int i)
{
 int k=i;
 while(k>=0)
 {
   a[k]++;
   if(a[k]<='9') return k;
   else
    {
        a[k]='0';
        k--;
   }
  }
  return k;
}
int main()
{
   char A[102];
   int n,t;
   scanf("%d",&n);
   for(t=0;t<n;t++)
   {
       printf("case #%d:\n",t);
       A[0]='0';
       scanf("%s",A+1);
       int len=strlen(A);
       int i,j;
       Add(A,len-1);
       for(i=1;i<len;i++)
      {
          if(A[i]==A[i-1]) break;
          }
    if(i!=len)
        {
         i=Add(A,i);
         while(i>0)
         {if(A[i]!=A[i-1]) break;
         i=Add(A,i);}
         }
    for(j=i+1;j<len;j++)
    {
     A[j]=(j-i+1)%2+'0';
    }
    if(A[0]!='0') printf("%c",A[0]);
    printf("%s\n",A+1);
   }
}
