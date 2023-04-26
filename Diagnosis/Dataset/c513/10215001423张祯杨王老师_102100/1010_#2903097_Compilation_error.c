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
   for(i=0;i<n;i++) a[i]=int(s[i]-48);
      for(i=0;i<=n;i++)
      { num=100*s[3i]+10*s[3i+1]+s[3i+2];
        trans(num,10);
      }
   if(m==1)
   {  num=s[len-1]
      trans(num,4);
   }
   if(m==2)
   { num=10*s[len-2]+s[len-1]
     trans(num,7);
   }
   return 0
}
