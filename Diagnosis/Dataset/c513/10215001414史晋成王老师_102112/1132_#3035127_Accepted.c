#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{ int i,j,n,m,k,h,T,r,s[10000],sum;
  char c,r1[10000];
  scanf("%d\n",&T);
  for(i=0;i<T;i++)
  { memset(s,0,sizeof(s));
    memset(r1,0,sizeof(r1));
   scanf("%d %d",&n,&r);
   j=0;
   while(n)
   {  if(n%r<10) {s[j]=n%r;j++;}
      else if(n%r>=10) {s[j]=n%r;j++;}
       n=n/r;
   }
   sum=0;
   for(k=0;k<j;k++)
   sum+=s[k];
   j=0;
   while(sum)
   {  if(sum%r<10) {r1[j]=sum%r+'0';j++;}
      else if(sum%r>=10) {r1[j]=sum%r-10+'A';j++;}
       sum=sum/r;
   }
   printf("case #%d:\n",i);
   for(k=strlen(r1)-1;k>=0;k--)
   printf("%c",r1[k]);
   printf("\n");
   
  }
    
}