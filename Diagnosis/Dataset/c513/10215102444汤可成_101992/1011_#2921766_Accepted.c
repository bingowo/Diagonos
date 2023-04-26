#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[1000] = {0};
    char t[100000] = {0};
    scanf("%s", s);
    int k = 0;
    int i = 0;
    //十六进制转二进制，一位对应四位
    for(i = 2; i<strlen(s); i++)
    {
        int n = 0;
        if(s[i]>='A') n = s[i]-'A'+10;
        else n = s[i] - '0';
        unsigned int flag = 0x8;  //1000
        while(flag)
        {
            if(n&flag) t[k++] = '1';
            else t[k++] = '0';
            flag = flag>>1;
        }
    }
    //二进制转十进制
    long long int qr = 0, qi = 0;  //实部虚部一开始均为零
    long long int a = 0, b = 0;
    for(i = 0; i<k; i++)
    {
        int r = t[i]-'0';   //r为余数
        a = -qr-qi+r;
        b = qr-qi;
        qr = a;
        qi = b;
    }
    //输出
    if(qi ==0 )
    {
        printf("%lld\n",qr);
    }
    else
    {
        if(qr != 0)
        {
            printf("%lld", qr);
            if(qi>0) printf("+");
        }
        if(qi==1)printf("i\n");
        else if(qi==-1)printf("-i\n");
        else
        {
            printf("%lldi\n",qi);
        }
    }
    return 0;
}
