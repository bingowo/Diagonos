#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{int T,i,b,c,j,k,h,m; int a[32]={0},d[32]={0};
scanf("%d",&T);
for(i=0;i<T;i++)
{scanf("%d %d",&b,&c);
  h=0;
  while(c)
 {d[h]=c%2;
  c=c/2;
  h++;} 
  m=0;
  while(b)
 {a[m]=b%2;
  b=b/2;
  m++;}
 if(m>h) h=m;
 k=0;
 for(j=0;j<h-1;j++)
 { if (a[j]!=d[j]) k++;
}
printf("%d\n",k);
}
    
}