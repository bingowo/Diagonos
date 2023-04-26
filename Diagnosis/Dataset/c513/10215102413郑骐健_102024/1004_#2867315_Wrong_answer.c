#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char n[16];//建立16进制的辅助数组
    for (int z = 0;z < 10;z++)
    {
        n[z] = '0' + z;
    }
    for (int z = 10;z < 16;z++)
    {
        n[z] = 'a' - 10 + z;
    }
    //确定变量类型，选择数据类型（int or double）
    char p[2000];
    while (scanf("%s", p)!= EOF)
    {
        int flag = 1;//判断是否为int
        int a = 0;
        while (p[a] != '\0')
        {
            if (p[a] == '.')
            {
                flag = 0;
                break;
            }
            a++;
        }
        //转化数据，转换为十六，8位为分隔，
        double m1;
        
        m1 = atof(p);
        if (flag)//int 情况
        {
            int m;
            m = (int)m1;
            char bin[32];
            for (int j = 0;j < 4;j++)
            {
                char k1 = n[m % 16];//暂时存储
                m /= 16;
                printf("%c%c ", n[m % 16],k1);
                    m /= 16;
            }
        }
        else//double情况
        {
           

        }
    }
  
    return 0;

}
