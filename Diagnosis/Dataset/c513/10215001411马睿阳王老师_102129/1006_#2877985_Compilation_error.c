#include<stdio.h>
#include<string.h>
int main()
{int T,i,b,j;char a[1000];
 scanf("%d",&T);
 for(i=0,j=0,b=0;i<T;i++)
 { j=0;b=0;
  scanf("%s",a);
  for(j=0;j<strlen(a);j++)
   { a[j]='\0';
   }
   for(i=0;i<121;i++)
   now[i]='0';
 while (a[j])
  { if(a[j]=='-') { b=(b-1)*3;}
   else  if(a[j]=='1') {b=(b+1)*3;}
   else  { b=b;}
   j++;
   if(j==strlen(a))b=b/3;

  }

  printf("case #%d:\n",i);
  printf("%d\n",b);
 }
return 0;
}
