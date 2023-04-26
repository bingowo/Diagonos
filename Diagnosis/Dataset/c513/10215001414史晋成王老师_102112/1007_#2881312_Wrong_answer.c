#include<stdio.h>
#include<stdlib.h>

int main()
{int T,n,i,j; int a[32];
for(i=0;i<T;i++)
{scanf("%d",&n);
int c=0;
 while(n)
 { a[c]=n%2;
   n=n/2;
   c++;  
 }
 int k=1,max=0;
 for(j=0;j<c-1;j++)
 {if(a[j]!=a[j+1]) k++;
  if(k>max) max=k;
  if(a[j]==a[j+1]) k=1;
     
 }
    printf("case #%d:\n",i);
    printf("%d",max);
}
    
}