#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{ int T,i,j,n,m,k,a[1000]={0},b[1000]={0},f;
char s[1000];
scanf("%d",&T);
for(i=0;i<T;i++)
{ scanf("%s",s);
  n=strlen(s);
  for(j=0;j<n;j++)
  { a[s[j]]+=1;
  }
  for(j=0;j<a['Z'];j++)
   b[0]+=1;
   for(j=0;j<a['G'];j++)
   b[8]+=1;
   for(j=0;j<a['X'];j++)
   b[6]+=1;
   for(j=0;j<a['S']-a['X'];j++)
   b[7]+=1;
   for(j=0;j<a['W'];j++)
   b[2]+=1;
   for(j=0;j<a['U'];j++)
   b[4]+=1;
   for(j=0;j<a['F']-a['U'];j++)
   b[5]+=1;
   for(j=0;j<a['O']-b[0]-b[2]-b[4];j++)
   b[1]+=1;
   for(j=0;j<a['R']-b[0]-b[4];j++)
   b[3]+=1;
   for(j=0;j<a['E']-b[8]-2*b[7]-b[5]-2*b[3]-b[1]-b[0];j++)
   b[9]+=1;
   for(k=0;k<10;k++)
   printf("%d",b[k]); printf("\n");
   memset(b,0,sizoeof(b));
}
    
}