#include <stdio.h>
#include <stdlib.h>

int main()
{
    char hex[100000];
    char bin[100000];
    char * p = bin;
    int pl = 0;
    scanf("%s",&hex);
    for(int i = 2; i < 100000 && hex[i] != '\0'; i++){
        int dex;
        if(hex[i] - 'A' >= 0){
            dex = hex[i] - 'A' + 10;
        }else if(hex[i] - '0' >= 0 && hex[i] - '9' <= 0){
            dex = hex[i] - '0';
        }//16->10
        //10->2
        int n;
        for (n = 8; n >= 1; n = n >> 1){
            if((dex & n) == 0){
                *(p + pl) = '0';
            }else {
                *(p + pl) = '1';
            }
            pl++;
        }
    }
    long long int qr = 0;
    long long int qi = 0;
    long long int a;
    long long int b;
    long long int r;
    for(int i = 0; i < pl; i++){
        r = *(p + i) - '0';
        a = - qr - qi + r;
        b = qr - qi;
        qr = a;
        qi = b;
    }
    if(qr == 0 && qi == 0){
        printf("0");
    }else if(qr != 0 && qi == 0){
        printf("%lld",qr);
    }else if(qi != 0 && qr == 0){
        if(qi == -1){
            printf("-i");
        }else if(qi == 1){
            printf("i");
        }else{
            printf("%lldi",qi);
        }
    }else if(qi != 0 && qr != 0){
        printf("%lld",qr);
        if(qi == -1){
            printf("-i");
        }else if(qi == 1){
            printf("+i");
        }else if(qi > 0){
            printf("%+lldi",qi);
        }else if(qi < 0){
            printf("%lldi",qi);
        }
    }
}
