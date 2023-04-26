#include<stdio.h>
#include<string.h>

typedef struct
{
    int binary[8];
}STRUCT;

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        char s[105];
        gets(s);   //gets遇到换行符会停止
        int len=strlen(s);
        STRUCT CASE[len];
        
        for(int j=0;j<len;j++)//读入
        {
            int temp;
            temp = s[j];//转化为ASCII值
            for(int r=0;r<8;r++)
            {
                CASE[j].binary[r] = temp % 2;
                temp = temp / 2;
            }
        }
        int add=0;
        if(len%3 != 0)
            add = 6 - (8*len)%6; //补0位
        int LEN;
        LEN = len*8 + add;//二进制位
        
        char ans[LEN];
        int r=0,t=0;
        for(int j=0;j<len;j++)
        {
            for(;CASE[j].binary[r] != '\0';r++,t++)
            {
                ans[t] = '0' + CASE[j].binary[r];
            }
            t++;
            r = 0;
        }
        if(add != 0)
        {
            for(int j=t;j<LEN;j++)
                ans[t] = '0';
        }
        int digit;
        digit = LEN/6;
        char LETTER[digit];
        for(int j=0;j<digit;j++)
        {
            int temp;
            temp = (ans[j*6+5] - '0')*1 + (ans[j*6+4] - '0')*2 + (ans[j*6+3] - '0')*4 + (ans[j*6+2] - '0')*8 + (ans[j*6+1] - '0')*16 + (ans[j*6+0] - '0')*32;
            LETTER[j] = temp;
            printf("%c",LETTER[j]);
        }
        if(digit < 4)
        {
            for(int j=0;j<4-digit;j++)
                printf("=");
        }
        printf("\n");
    }
    return 0;
}
