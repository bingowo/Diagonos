#include<stdio.h>
int main()
{int T,i=0,a[1000],b=0,j=0;
 scanf("%d",&T);
 for(i=0;i<T;i++)
 {scanf("%d",a);
  while(a!=0)
  {if(a[j]==1)  {b=(b+1)*3;}
  else if(a[j]=='-'') {b=(b-1)*3;}
  else if(a[j]==0) { b=b;}
   j++;
  }
  printf("case #%d:\n",i);
  printf("%d",b);
 }
return 0;
}
