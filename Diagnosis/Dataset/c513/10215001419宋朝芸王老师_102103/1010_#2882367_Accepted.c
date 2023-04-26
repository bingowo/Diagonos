#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void binary(int num, int* a, int len)
{

    for(int j = len;j > 0; j--)
    {
        a[j-1] = num % 2;
        num /= 2;
    }
}

void print(int num, int* a)
{
    for(int j = 0;j < num;j++)
    {
        printf("%d",a[j]);   //输出num个数
        a[j] = 0;            //对a数组初始化
    }
}


int main()
{
    int tempA[10] = {0};
    char input[500] = {'\0'};
    char *p = input;
    int i = 0;                  //i存储输入字符的个数
    int tempI;

    scanf("%s",input);
    i = strlen(input);

    printf("0001");             //输出数字编码的标志*
    binary(i,tempA,10);            //把数字的个数转为二进制并存入tempA
    print(10,tempA);            //输出数字的个数*并且对tempA初始化
    while(i >= 3)
    {
        tempI = ((*p) - '0')*100 + ((*(p+1)) - '0')*10 + (*(p+2)) - '0';
        binary(tempI,tempA,10);    //把前面3位转化成二进制并存入tempA
        print(10,tempA);        //输出二进制串*并且对tempA初始化
        p += 3;
        i -= 3;
    }
    if(i == 2)
    {
        tempI = ((*p) - '0')*10 + (*(p + 1)) - '0';
        binary(tempI,tempA,7);
        print(7,tempA);
        return 0;
    }
    if(i == 1)
    {
        tempI = (*p) - '0';
        binary(tempI,tempA,4);
        print(4,tempA);
        return 0;
    }
    return 0;
}
