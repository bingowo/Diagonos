#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 100

int main()
{
    int i,d,k=0,r;
    char s[N],t[N];
    scanf("%s",s);
    for(i=2;i<strlen(s);i++)
    {
        if(s[i]<'A')d=s[i]-'0';
        else d=s[i]-'A'+10;
        unsigned int b=0x8;
       while(b)
       {
           if(d&b)t[k++]='1';
           else t[k++]='0';
            b>>=1;
       }
    }
  long long int qi=0,qr=0,a,b;
  for(k=0;k<strlen(t);k++)
  {
      r=t[k]-'0';
      a=-qr-qi+r;
      b=qr-qi;
      qr=a;qi=b;
  }
  if(qr==0)printf("%lldi\n",qi);
  else if(qi==0)printf("%lld",qr);
  else if(qi>0)
  {
      if(qi==1)printf("%lld+i",qr);
  else printf("%lld+%lldi",qr,qi);
  }
  else if(qi==-1)
  {
      if(qi==1)printf("%lld-i",qr);
   else  printf("%lld%lldi",qr,qi);
    }
    return 0;
}
