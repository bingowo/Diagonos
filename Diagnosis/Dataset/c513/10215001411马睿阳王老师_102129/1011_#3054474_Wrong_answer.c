#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int i=0,d=0,l=0,k=0,r=0;
    char s[100000],t[100000];
    scanf("%s",s);
    l=strlen(s);
    for(i=2;i<l;i++)
    {
        if(s[i]<'A') d=s[i]-'0';//字符串向数组转化
        else d=s[i]-'A'+10;
        unsigned int b=8;//十六进制向二进制转化，而且8不能带有符号
        while(b)
        {
            if(d&b) t[k++]='1';//注意如果给字符串赋值，需要‘’
            else t[k++]='0';
            b>>=1;//等于号！！
        }
    }
    long long int qi=0,qr=0,a,b;//注意取值范围
    for(k=0;k<l;k++)
    {
        r=t[k]-'0';
        b=qr-qi;
        a=-qr-qi+r;
        qr=a;
        qi=b;
    }
    //认真处理分类输出的问题
    if(qr==0)
    {
        if(qi==0) printf("0");
        else if(qi==-1||qi==1) printf(qi>0?"i":"-i");
        else printf("%lldi",qi);
    }
    else
    {
        if(qi==0) printf("%lld",qr);
        else if(qi==-1||qi==1) printf("%lld%ci",qr,qi>0?'+':'-');
        else if(qi>0)  printf("%lld+%lldi",qr,qi);
        else printf("lld%lldi");
    }
    return 0;
}
