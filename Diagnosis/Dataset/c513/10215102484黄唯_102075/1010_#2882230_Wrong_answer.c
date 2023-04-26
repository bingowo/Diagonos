//
// Created by Shizumu on 2022/2/23.
//
#include <stdio.h>
#include <string.h>

void itob(unsigned n, char s[])
{
    int i;
    for(i = 98; n && i; n /= 2){
        s[i--] = (((n % 2) < 10) ? '0' : ('A' - 10)) + (n % 2);
    }
    memmove(s , s + i + 1, 99 - i- 1);
    s[99 - i- 1] = '\0';
}

void PrintBit(char s[], int length)
{
    int len = strlen(s);
    if(len < length){
        for(int i = 0; i < (length - len); i ++){
            printf("0");
        }
    }
    printf("%s", s);
}
// 这里没有存储任何一个bit，而是把数据直接输出节省空间 

int main(void)
{
    char s[501], temp[100];
    scanf("%s", s);
    int tempnum = 0, len = strlen(s);
    itob(len, temp);
    printf("0001");
    PrintBit(temp, 10);
    for(int i = 0 ; i < len; i ++){
        tempnum = tempnum * 10 + (s[i] - '0');
        if(i % 3 == 2){
            itob(tempnum, temp);
            PrintBit(temp, 10);
            tempnum = 0;
        }
    }
    if(len % 4 == 1){
        itob(tempnum, temp);
        PrintBit(temp, 4);
        tempnum = 0;
    }else if(len % 3 == 2){
        itob(tempnum, temp);
        PrintBit(temp, 7);
        tempnum = 0;
    }

    return 0;
}
