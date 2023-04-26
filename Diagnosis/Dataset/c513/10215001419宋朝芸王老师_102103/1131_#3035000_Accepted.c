#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

long long int convert(char s[N], int len){
    long long int ret = 0;
    int i = 0;
    if(s[0] == '-') i++;
    while(i < len){
        ret = ret*10 + s[i++] - '0';
    }
    return ret;
}

int main()
{
    /****input****/
    long long int a,b,c = 0;
    char sa[N] = {'\0'}, sb[N] = {'\0'};
    scanf("%s%s",sa,sb);

    //convert into lld
    int sym_flag = 0;
    if(sa[0] == '-') sym_flag = 1;
    a = convert(sa, strlen(sa));
    b = convert(sb, strlen(sb));

    //special cases
    if(a == b) {
        printf("1");
        return 0;
    }
    if(a == 0) {
        printf("0");
        return 0;
    }


    /****into Three****/
    //char tri[1000];
    char intPart[10000] = {'\0'};
    char decPart[10000] = {'\0'};
    int numInt = 0, numDec = 0;
    int flag = 0;   //no dec part

    if(a > b){  //real
        c = a/b;
        a = a%b;
    }

    while(c > 0){         //into three:int
        intPart[numInt++] = c%3 + '0';
        c /= 3;
    }

    if(a != 0) flag = 1; //into three:float
    while(a != 0){
        int temp = 0;
        if(a*3/b >= 2) temp = 2;
        else if(a*3/b >= 1) temp = 1;

        decPart[numDec++] = temp + '0';
        a = a*3 - temp*b;
    }


    /****into balanced Three****/
    int add = 0;        //add

    if(flag == 1){
    for(int i = numDec; i > 0; i--){    //add:dec
        int temp = decPart[i-1] - '0';

        if(add > 0){
            temp++;
            add--;
        }

        if(temp + 1 > 2){
            decPart[i-1] = temp + 1 - 3 + '0';
            add ++;
        }
        else decPart[i-1] = temp + 1 + '0';
    }}

    for(int i = 0; i < numInt; i++){    //add:int
        int temp = intPart[i] - '0';

        if(add > 0){
            temp++;
            add--;
        }

        if(temp + 1 > 2){
            intPart[i] = temp + 1 - 3 + '0';
            add ++;
        }
        else intPart[i] = temp + 1 + '0';
    }


    for(int i = 0; i < numInt; i++){    //minus:int
        if(intPart[i] == '0') intPart[i] = '2';
        else intPart[i] = intPart[i] -1;
    }
    if(flag == 1){
    for(int i = 0; i < numDec; i++){    //minus:dec
        if(decPart[i] == '0') decPart[i] = '2';
        else decPart[i] = decPart[i] -1;
    }}


    if(add > 0) intPart[numInt++] = '1';    //add:int more


    /****output****/
    while(decPart[numDec-1] == '0') numDec--;
    while(intPart[numInt-1] == '0') numInt--;

    for(int i = numInt; i > 0; i--){    //print int
        if(sym_flag == 0) printf("%c",intPart[i-1]);
        else if(intPart[i-1] == '0') printf("0");
        else printf("%d",3-intPart[i-1]+'0');
    }
    if(flag != 1) return 0;

    if(numInt == 0) printf("0");
    printf(".");    //print dec
    for(int i = 0; i < numDec; i++){
        if(sym_flag == 0) printf("%c",decPart[i]);
        else if(decPart[i] == '0') printf("0");
        else printf("%d",3-decPart[i]+'0');
    }

    return 0;
}
