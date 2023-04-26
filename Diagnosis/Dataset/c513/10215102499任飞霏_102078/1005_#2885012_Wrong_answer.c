#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n,i;
    // 存储八进制小数，十进制小数

    scanf("%d",&n);
    for(i = 0;i < n;i++){
        char octal[55],decimal[155];
        scanf("%s",octal);
        printf("case #%d",i);
        int numbers = 0;
        int len = strlen(octal) - 1;
        for(;len != 1;--len){
            int digit = octal[len] - '0';
            int j = 0,temp;
            do{
                if(j < numbers)
                    {temp = digit*10 + decimal[j] - '0';}
                else{
                    temp = digit * 10;
                }
                decimal[j++] = temp/8 + '0';
                digit = temp%8;

            }while(digit != 0||j < numbers);
            numbers = j;
        }
        decimal[numbers] = '\0';
        printf("0.%s",decimal);
    }
    return 0;
}
