#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define length 170

//一个进位器，乘法器
//int 型数组储存每一位。

void multiply(int* p, int n, int* p1)      //根据n对p的每一位进行乘法运算,将结果储存在p1中;如果p1为空指针，则将结果储存在p中
{
    switch (n)//退位
    {
    case 2:for (int z = 0; z < length - 2;z++)
    {
        *(p1 + z + 2) = *(p + z);
    }
          p1[0] = 0;
          p1[1] = 0;
          break;
    case 5:
        for (int z = 0; z < length - 3;z++)
        {
            *(p1 + z + 3) = *(p + z);
        }
        p1[0] = 0;
        p1[1] = 0;
        p1[2] = 0;
        break;

    case 1:
        for (int z = 167; z > -1;z--)
        {
            *(p + z + 1) = *(p + z);
        }
        *p = 0;
        return;
        break;
    }
        //乘法
    int next = 0;
        for (int t = length-1;t > -1;t--)
        {

            *(p1 + t) = *(p1 + t) * n + next;
            next = 0;
            if (!(*(p1 + t) < 10))
            {
                next= *(p1 + t) / 10;
                *(p1 + t) = *(p1 + t) % 10;
            }
        }
    }

void add(int* p1, int* p2)  //将p2上每一位加到p1上
{
    for (int t = length-1;t >-1;t--)
    {
        *(p1 + t) = *(p1 + t) + (*(p2 + t));
        if (!(*(p1 + t) < 10))
        {
            *(p1 + t) -= 10;
            *(p1 + t - 1) += 1;
        }
    }
}
void reverse(int* p)
{
    int p2[170],p5[170];//分别记录乘以0.1,0.02,0.005
    multiply(p, 2,p2);
    multiply(p, 5,p5);
    multiply(p, 1,p2);
    add(p, p2);
    add(p, p5);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0;i < T;i++)
    {
        int num[length];
        for (int i = 0;i < 170;i++)
        {
            num[i] = 0;
        }
        char num_1[170];
        scanf("%s", num_1);
        for (int z = strlen(num_1)-1;z > 1;z--)//每一次循环将最后一位移入数组第一位，然后进行乘法
        {
            num[0] += (num_1[z]-'0');
            reverse(num);
        }
        int g;//记录数组最后一个数
        for (g = length-1;g > -1;g--)
        {
            if (num[g] != 0)break;
        }
    //输出
        printf("case #%d:\n0.",i);
        for (int z = 1;z < g+1;z++)
        {
            printf("%d", num[z]);
        }
        printf("\n");
    }
    return 0;
}
