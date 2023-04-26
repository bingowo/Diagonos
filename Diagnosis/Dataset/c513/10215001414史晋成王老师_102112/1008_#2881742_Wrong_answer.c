#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{int T,i,b,c,j,k,h; int a[32]={0},d[32]={0};
scanf("%d",&T);
for(i=0;i<T;i++)
{scanf("%d %d",&b,&c);
  h=0;
  while(c)
 {d[h]=c%2;
  c=c/2;
  h++;
     
 } h=0;
  while(b)
 {a[h]=b%2;
  b=b/2;
  h++;
     
 }
 j=0; k=0;
 while ((a[j]!=0)||(d[j]!=0))
 { if (a[j]!=d[j]) k++;
    j++;
 }

}
    
}