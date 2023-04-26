#include <stdio.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d", &t);
    for(int k=0; k<t; k++)
    {
    char Octal[55], decimal[155];
    scanf("%s", Octal);
    int numbers = 0; //十进制小数长度
    int len = strlen(Octal) - 1;
    int temp, digit, j;
    for( ; len!=1; len--)//从后向前依次取八进制各个位上的数字
    {
        digit = Octal[len] - '0';
        j=0;
        do//进入除法
        {
        if(j < numbers)//余数乘于10加下一位
        temp = digit*10 + decimal[j] - '0';
        else //余数乘于10加下一位0
        temp = digit*10;
        decimal[j++] = temp/8 + '0';
        digit = temp%8;
        }
        while(digit!=0 || j<numbers);//余数为0且所有数都参与除8
        numbers = j;//修改十进制位数
    }
    decimal[numbers] = '\0';
    printf("case #%d:\n", k);
    printf("0.%s\n", decimal); 
    }
    return 0;
}