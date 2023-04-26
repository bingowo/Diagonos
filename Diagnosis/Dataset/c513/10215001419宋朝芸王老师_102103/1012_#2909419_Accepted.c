#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    long long int qr = 0, qi = 0, a, b;

    char ca[50];
    scanf("%s",ca);
    
    /***处理输入***/
    if(strcmp(ca,"i") == 0){qr = 0; qi = 1;}
    else if(strcmp(ca,"-i") == 0){qr = 0; qi = -1;}
    else{
         long long int temp = 0;
        char *pa = ca;
        int flag= 1;
    
        /***读数字（假设为实部）***/
        if(*pa == '-') {flag = -1; pa++;}
        if(*pa == '+') pa++;
        while(isdigit(*pa)){
            temp = temp * 10 + *pa - '0';
            pa++;
        }
        temp *= flag;

        if(*pa == 'i')  qi = temp;
        else if(*pa == '\0') qr = temp;
        else{
        /***读虚部数字***/
            if(*pa == '-') {qr = temp; qi = -1; pa++;}
            if(*pa == '+') {qr = temp; qi = 1; pa++;}
            flag = 0;
            temp = 0;
            if(*pa == 'i') flag = 1;
            while(isdigit(*pa)){
                temp = temp * 10 + *pa - '0';
                pa++;
            }
            if(flag != 1) qi *= temp;
        }
    }

    /***进制转换***/
    //qr+qi i =(a=bi)(-1+i)+r
    //a = (qi + r -  qr)/2
    //b = -(qr + qi - r)/2

    int ans[10000]={0};
    int num = 0;
    do{
        int r = 1;
        if(abs(qr)%2 == abs(qi)%2) r = 0;
        ans[num++] = r;

        a = (qi - qr + r)/2;
        b = -(qr + qi - r)/2;

        qr = a;
        qi = b;
    }while(a != 0 || b != 0);

    while(num > 0){
        printf("%d",ans[num - 1]);
        num--;
    }

    return 0;
}
