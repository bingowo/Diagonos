#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
    int T = 0,R = 0;
    scanf("%d",&T);

    for(R = 0; R < T; R++){
        char oct[52];       //存放所有输入
        char dec[155];      //只存放小数
        int numbers = 0;    //记录十进制小数位数(从1开始)
        int len = 0;        //记录八进制读到的下标

        scanf("%s",oct);
        len = strlen(oct) - 1;

        for(; len != 1; --len){
            int digit = oct[len] - '0';     //目前指向的数（八进制或者来自上次的商中某一位或余数）
            int temp;       //记录被除数
            int j = 0;          //十进制小数下标

            do{
                if(j < numbers)
                    temp = digit*10 + dec[j] - '0';
                else temp = digit*10;

                dec[j] = temp/8 + '0';  //重新存小数
                digit = temp%8;
                j++;
            }
            while(digit != 0 || j < numbers);
            numbers = j;
        }
        dec[numbers] = '\0';

        printf("case #%d:\n0.%s\n",R,dec);
    }
    return 0;
}