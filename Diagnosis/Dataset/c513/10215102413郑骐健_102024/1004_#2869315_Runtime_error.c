#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>


void output(int size,  void* p)
{
    
    unsigned char* p1 = p;
    for (int i = 0;i < size;i ++)
    {
        printf("%02x ", *(p1+i));
    }
    printf('\n');
}
int main()
{
    //确定变量类型，选择数据类型（int or double）
    char p[2000];
    while (scanf("%s", p) != EOF)
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
        if (flag)//int 情况
        {
            int m1;
            m1 = atoi(p);
            int n = sizeof(int);
            output(n, &m1);

        }
        else//double情况
        {
            double m2 = atof(p);
            int n = sizeof(double);
            output(n, &m2);
    }
}
    return 0;

}
