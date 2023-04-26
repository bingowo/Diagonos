#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{ int n,i,j,t,k,p; char s[110],a[8000];
scanf("%d\n",&n);
for(i=0;i<n;i++)
{ gets(s);
 j=0;k=0;
 while(s[j])
 { t=s[j];
 for(k=(j+1)*8-1;k>=8*j;k--)
 { a[k]=t%2;
   t=t/2;
 }
  j++;
 }
for(p=0;p<k;p++)
  { printf("%d",a[p]);
  }
  printf("\n");
}
}