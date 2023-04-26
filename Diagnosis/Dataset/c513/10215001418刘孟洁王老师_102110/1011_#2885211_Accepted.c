#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>
#define N 100000

int main()
{
    int i,d,k=0,r;
    char s[N],t[N];
    scanf("%s",s);
    for(i=2;i<strlen(s);i++)
    {
        if(s[i]<'A')d=s[i]-'0';
        else d=s[i]-'A'+10;
        unsigned int g=0x8;
       while(g)
       {
           if(d&g)t[k]='1';
           else t[k]='0';
            g>>=1;
            k++;
       }
    }
  long long int qi=0,qr=0,a,b;
  for(k=0;k<strlen(t);k++)
  {
      r=t[k]-'0';
      a=-1*qr-qi+r;
      b=qr-qi;
      qr=a;qi=b;
  }


 if(qr==0)
 {
     if(qi==0)printf("0");
     else if(qi==-1||qi==1)printf(qi>0?"i":"-i");
     else printf("%lldi",qi);
 }
 else
 {
     if(qi==1||qi==-1)printf("%lld%ci",qr,qi>0?'+':'-');
     else if(qi==0)printf("%lld",qr);
     else if(qi>0)printf("%lld+%lldi",qr,qi);
     else printf("%lld%lldi");
 }
    return 0;
}
