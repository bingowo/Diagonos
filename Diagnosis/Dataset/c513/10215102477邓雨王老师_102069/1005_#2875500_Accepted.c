#include <stdio.h>
#include <string.h>

//这里的整体思路是考虑使用秦九韶算法，来降低编写难度和提高效率（可以自行百度）
/*
例如：
对于0.754的转换，我们可以按照这个顺序：
((4 * 1/8) + 5) * 1/8 + 7 ) * 1/8 
来得到答案 
*/ 

void FloatAdd(char in[], int num)
{
    int len = strlen(in);
    memmove(in + 1, in, len + 1);
    in[0] = num +'0';
}

void FloatDivide(char in[], char out[])		//这里做的是高精度除法，除法部分只传入了小数部分，这样相当于一次整数运算。 
{
    int len = strlen(in);
    int temp, remainder = in[0] - '0', quotient = 0, index = 0;
    for(int i = 0 ; i < len || remainder != 0; i ++){
        if(i >= len - 1){
            temp = remainder * 10;
        }else{
            temp = remainder * 10 + in[i + 1] - '0';
        }
        quotient = temp / 8;
        remainder = temp % 8;
        out[index ++] = quotient + '0';
    }
}

void FloatOctToDec(char oct[], char dec[])
{
    int len = strlen(oct), tlen = 0;
    char temp[180] = {0};
    for(int i = len - 1; i >= 0; i --){
        FloatAdd(dec, oct[i] - '0');		//这里模拟的是秦九韶算法的“加”的步骤 
        FloatDivide(dec, temp);				//这里模拟的是秦九韶算法的“乘”的步骤 
        tlen = strlen(temp);
        memmove(dec, temp, tlen + 1);
    }
}


int main(void)
{
    int t;
    scanf("%d", &t);
    for(int i = 0 ; i < t; i ++){
        char s[60], oct[60], dec[180] = {0};
        scanf("%s", s);
        int len = strlen(s);
        memmove(oct, s + 2, len - 1);		//清除了小数点 
        FloatOctToDec(oct, dec);
        printf("case #%d:\n", i);
        printf("0.%s\n", dec);
    }

    return 0;
}