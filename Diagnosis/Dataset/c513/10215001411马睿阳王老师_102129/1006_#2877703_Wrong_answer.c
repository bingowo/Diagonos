#include<stdio.h>
#include<string.h>
int main()
{int T,i,a[1000],b,j;
 scanf("%d",&T);
 for(i=0,j=0,b=0;i<T;i++)
 {scanf("%s",a);
 do
  {if(a[j]==1) { b=(b+1)*3;}
   else  if(a[j]=='-') {b=(b-1)*3;}
   else  { b=b;}
   j++;
   if(j==strlen(a))b=b/3;
  }
  while (a[j]);
  printf("case #%d:\n",i);
  printf("%d",b);
 }
return 0;
}
