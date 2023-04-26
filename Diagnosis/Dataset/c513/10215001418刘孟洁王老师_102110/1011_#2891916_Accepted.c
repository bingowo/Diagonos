#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>
#define N 100000//注意数组大小范围！！

int main()
{
    int i,d,k=0,r;
    char s[N],t[N];
    scanf("%s",s);
    for(i=2;i<strlen(s);i++)
    {
        if(s[i]<'A')d=s[i]-'0';
        else d=s[i]-'A'+10;
        unsigned int b=8;//0x8和8都一样，都表示8，这里因为8的二进制时1000四位，十六进制转二进制，是一转四，所以用8
       while(b)//还要注意8在哪里开始定义
       {
           if(d&b)t[k++]='1';
           else t[k++]='0';/*这样操作是进行后+1，[++k]是+1后操作*/
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


 if(qr==0)//要好好处理分类输出的问题，想清楚
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
