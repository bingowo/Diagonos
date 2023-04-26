#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{ unsigned long long int n,i,k,j,s,t;
   int a[1000],flag;
   scanf("%llu",&n);
   for(k=n;k<n+1;k++)
   {s=k;i=0;t=k;
    while(s!=0) 
  { a[i]=s%10;
    s=s/10;
    i++;
  }
  flag=0;
   for(j=i-1;j>=0;j--)
   {if(a[j]==9) flag=1;}

  if(t%9!=0&&flag==0) {printf("%llu",t);}
  memset(a,0,sizeof(a));
   }
}



