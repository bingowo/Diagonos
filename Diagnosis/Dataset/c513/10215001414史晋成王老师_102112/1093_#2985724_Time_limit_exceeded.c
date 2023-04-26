#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{ unsigned long long int n,i,k,j,s,t;
   int a[1000],flag;
   scanf("%llu",&n);
   for(k=n;;k++)
   {s=k;i=0;
  while(k!=0) 
  { a[i]=k%10;
    k=k/10;
    i++;
  }
  flag=0;
  for(j=i-1;j>=0;j--)
   if(a[j]==9) {flag=1;}
  if(flag==1) continue;
  if(s%9!=0&&flag==0) {printf("%llu",s);break;}
  memset(a,0,sizeof(a));
   }
}



