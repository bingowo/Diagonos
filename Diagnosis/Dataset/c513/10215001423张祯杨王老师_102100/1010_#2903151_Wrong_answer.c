#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void trans(int ia,int ws)
{   int a[ws],i=0,j;
    while(ia!=0)
    { a[i++]=ia%2;
      ia/=2;
    }
    for(j=i;j<ws;j++) printf("0");
    for(;i>0;i--) printf("%d",a[i]);
}

int main()
{ char s[500];
  int m,n,i,num,a[500];
  scanf("%s",&s);
  int len=strlen(s);
  m=len%3,n=len/3;
   printf("0001");
   trans(len,10);
   for(i=0;i<len;i++) a[i]=s[i]-48;
      for(i=0;i<=n;i++)
      { num=100*a[3*i]+10*a[3*i+1]+a[3*i+2];
        trans(num,10);
      }
   if(m==1)
   {  num=a[len-1];
      trans(num,4);
   }
   if(m==2)
   { num=10*a[len-2]+a[len-1];
     trans(num,7);
   }
   return 0;
}
