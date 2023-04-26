
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef long long int lli;

lli llabs(lli x)		//对于long long int的特殊的绝对值函数 
{
    return x > 0? x : -x;
}


void PrintComplex(lli rel, lli img)
{
    if(rel != 0){
        if(rel < 0){
            printf("-");
        }
        printf("%lld", llabs(rel));
    }else if(img == 0){
        printf("0");
    }
    if(img != 0){
        if(img < 0){
            printf("-");
        }else if(img > 0 && rel != 0){
            printf("+");
        }
        if(img != 1 && img != -1){
            printf("%lld", llabs(img));
        }
        printf("i\n");
    }
}

void HexToBin(char s[], char b[])
{
    int len = strlen(s);
    int digit = 0, index = 3, count = 0;
    for(int i = 0 ; i < len ; i ++){
        if(isdigit(s[i])){
            digit = s[i] - '0';
        }else{
            digit = s[i] - 'A' + 10;
        }
        if(digit == 0){
            for(int j = 0 ; j < 4; j ++){
                b[index--] = '0';
                count ++;
            }
        }else{
        	//对于变换，必须要补齐4位，不然的话运算上会出现问题。 
            while(digit > 0 || count % 4 != 0){
                if(digit > 0){
                    b[index --] = digit % 2 + '0';
                    digit /= 2;
                }else{
                    b[index--] = '0';
                }
                count ++;
            }
        }
        index += 8;
    }
    b[index - 3] = '\0';
}

int main(void)
{
    char s[40], bi[160];
    scanf("%s", s);
    int len = strlen(s);
    memmove(s, s + 2, len - 1);
    HexToBin(s, bi);
    lli qr = 0, qi = 0, a, b;
    for(int i = 0; bi[i]; i ++){
    	//这里是题目条件推出来的运算公式 
        lli remainder = bi[i] - '0';
        a = -qr - qi + remainder;
        b = qr - qi;
        qr = a;
        qi = b;
    }
    PrintComplex(a, b);
	
	return 0; 
}