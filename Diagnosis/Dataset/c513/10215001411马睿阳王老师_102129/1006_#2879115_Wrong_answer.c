#include<stdio.h>
#include<string.h>
int main()
{int T,i,b,j;char a[1000];
 scanf("%d",&T);
 for(i=0,j=0,b=0;i<T;i++)
 { 
  scanf("%s",a);
  j=0,b=0;
 while (a[j])
  { if(a[j]=='-') { b=(b-1)*3;}
   else  if(a[j]=='1') {b=(b+1)*3;}
   else  { b=b;}
   j++;
   if(j==strlen(a))b=b/3;
  
  }
   j=0;b=0;
   for(j=0;j<strlen(a);j++)
   { a[j]='\0';
   }


  printf("case #%d:\n",i);
  printf("%d\n",b);
 }
return 0;
}
