#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        char s[60],t[160];//s存放八进制，t存放十进制
        scanf("%s",s);
        int numbers=0;//numbers记录当前十进制小数的位数
        int i=strlen(s)-1;//从八进制小数的最后一位开始
        for(;i!=1;i--)
        {
            int digit=s[i]-'0';//digit表示当前八进制小数的那个数字
            int j=0;
            int temp;
            do
            {
                if(j<numbers)
                {
                    temp=digit*10+t[j]-'0';
                }
                else
                {
                    temp=digit*10;
                }
                t[j++]=temp/8+'0';
                digit=temp%8;
            }while(digit!=0 || j<numbers);
            numbers=j;
        }
        t[numbers]='\0';
        printf("case #%d:\n0.",cas);
        printf("%s\n",t);
    }
    return 0;
}

