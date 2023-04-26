#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//用十六进制输入，转为二进制，再用-1+i进制转化成a+bi
int main()
{
    char hex[18];
    int bin[100]={0};
    int lenHex = 0,lenBin = 0;  //记录位数
    scanf("0x%s",hex);
    lenHex = strlen(hex);

    for(int i = 0; i < lenHex; i++){
        int temp;
        if(hex[i]>='A') temp = hex[i] - 'A' + 10;
        else temp = hex[i] - '0';

        unsigned int flag = 0x8;
        while(flag){
            if(temp & flag) bin[lenBin++] = 1;
            else bin[lenBin++] = 0;
            flag = flag >> 1;
        }
    }

    long long int qr = 0, qi = 0, a = 0, b = 0;
    for(int i = 0; i < lenBin ;i++){
        int r = bin[i];
        a = -qr -qi + r;
        b = qr - qi;
        qr = a;
        qi = b;
    }

    if(qi == 0) {printf("%lld",qr);return 0;}

    if(qr == 0 && qi != 1 && qi != -1) {printf("%lldi",qi);return 0;}
    if(qr == 0 && qi == 1) {printf("i",qi);return 0;}
    if(qr == 0 && qi == -1) {printf("-i",qi);return 0;}
    if(qi > 0 && qi != 1) {printf("%lld+%lldi",qr,qi);return 0;}
    if(qi > 0 && qi == 1) {printf("%lld+i",qr,qi);return 0;}
    if(qi < 0 && qi == -1) {printf("%lld-i",qr,qi);return 0;}
    printf("%lld%lldi",qr,qi);return 0;

}
