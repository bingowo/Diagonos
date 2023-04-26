#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{int t,i,j,n,r,flag,f; char s[100][100],k[100],c[100];
scanf("%d",&t);
for(i=0;i<t;i++)
{ scanf("%s",k);
printf("case #%d:\n",i);
n=strlen(k);f=0;
for(j=0;j<n;j++)
{ flag=1;
  for(r=j+1;r<n;r++)
  if(k[r]==k[j])  {flag=0;break;}
  if(flag==1) {c[f]=k[j];f++;}
}
c[f]=0;
printf("%s\n",c);
}
    
}