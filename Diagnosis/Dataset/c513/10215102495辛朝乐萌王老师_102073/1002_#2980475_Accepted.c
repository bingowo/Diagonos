#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>

/*
0~9 --> 0 -- 9
A~Z --> 10 -- 35
a~z --> 36 -- 61
按照这个对应法则构建数列
*/

int ChangeIndex(char c)  //这个函数是将字符转化为上述的编号 
{
    int ret;
    if(isdigit(c)){
        ret = c - '0';
    }else if(isupper(c)){
        ret = c - 'A' + 10;
    }else{
        ret = c - 'a' + 36;
    }
    return ret;
}

int main(void)
{
    char s[61];
    int isFind[62], CroNum[62];
    int t;
    scanf("%d", &t);
    for(int i = 0 ; i < t; i ++){
        memset(isFind, -1, sizeof(isFind));
        memset(CroNum, -1, sizeof(CroNum));
        // 设置没有出现的数值为-1，以便于之后的判断。 
        scanf("%s", s);
        int len = strlen(s);
        for(int j = 0 ; j < len; j ++){
            //存储这个字符串中每一个字符的编号，以便于之后在CroNum[]数组中设置对应数值 
   isFind[j] = ChangeIndex(s[j]);
        }
        int Number = 0;
        unsigned long long outNum = 0;
        for(int j = 0 ; j < len; j ++){
            if(CroNum[isFind[j]] == -1){
                if(j == 0){
                 //将第一个遇见的符号对应的编号设置为1，这是最小的情况。 
                    CroNum[isFind[j]] = 1;
                }else if(Number == 0){
                 //接下来，第二个符号应该是0 
                    CroNum[isFind[j]] = Number;
                    Number = 2;
                }else{
                 //第三个符号一次增加即可 
                    CroNum[isFind[j]] = Number;
                    Number ++;
                }
            }
        }
        if(Number == 0){
            //处理二进制的特殊情况，Number在这里还充当了进制 
   Number = 2;
        }
        for(int j = 0 ; j < len ; j ++){
            outNum = outNum * Number + CroNum[isFind[j]];
        }
        printf("case #%d:\n", i);
        printf("%llu\n", outNum);
    }

    return 0;
}
            