#include <stdio.h>
#include <stdlib.h>
#define N 10000


int main()
{
    char a[N]; //double类型需要64位存储，8个字节
    unsigned long long Ans;

    while(scanf("%s",a))
    {
        int flag = 0;
        char *p = a;

        while(*p)                         //可用strchr实现，在string.h中
        {
            if(*p == '.') flag = 1;     //有小数点
            p++;
        }

        if(flag == 1)
        {
            Ans = (unsigned long long)atof(a);   //double类型存储在long long

            for(int i = 0; i < 8; i++)
            {
                printf("%02x ",0|Ans);
                Ans = Ans >> 8;
            }
            printf("\n");
        }

        else
        {
            Ans = (unsigned long long)atof(a);  //转化成int类型

            for(int i = 0; i < 4; i++)
            {
                printf("%02x ",0|Ans);
                Ans = Ans >> 8;
            }
            printf("\n");
        }

        for(int i=0;i<N;i++)   a[i]='\0';   //对a初始化
    }
    return 0;
}
