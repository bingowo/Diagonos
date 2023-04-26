#include <stdio.h>
#include <string.h>


void FloatAdd(char in[], int num)
{
    int len = strlen(in);
    memmove(in + 1, in, len + 1);
    in[0] = num +'0';
}

void FloatDivide(char in[], char out[])	
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
        FloatAdd(dec, oct[i] - '0'); 
        FloatDivide(dec, temp);	 
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
        memmove(oct, s + 2, len - 1); 
        FloatOctToDec(oct, dec);
        printf("case #%d:\n", i);
        printf("0.%s\n", dec);
    }

    return 0;
}
