#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
typedef struct
{
    long long R;
    long long H;
    long long RH;
    int flag;
}COLUMN;
int compar(const void* p1, const void* p2);
int comparR(const void* p1, const void* p2)
{
    int flag = 0;
    long long Ra, Rb;
    COLUMN* a = (COLUMN*)p1, * b = (COLUMN*)p2;
    Ra = a->R;
    Rb = b->R;
    if (a->flag == 0 && b->flag == 1)
    {
        flag = -1;
    }
    else if (a->flag == 1 && b->flag == 0)
    {
        flag = 1;
    }
    else
    {
        if (Ra > Rb)
            flag = -1;
        else
            flag = 1;
    }

    return flag;
}
void myPrint(char* a);
int main()
{
    int n, m, i, j;
    long long res, temp, temp1, Rmax;
    scanf("%d %d", &n, &m);
    COLUMN* a = (COLUMN*)malloc(n * sizeof(COLUMN));
    for (i = 0;i < n;i++)
    {
        scanf("%lld %lld", &a[i].R, &a[i].H);
        a[i].RH = a[i].R * a[i].H;
        a[i].flag = 0;                //代表未被选中
    }
    qsort(a, n, sizeof(COLUMN), compar);
    res = 0;
    Rmax = 0;
    temp1 = 0;
    for (i = 0;i < m - 1;i++)
    {
        res += 2 * a[i].RH;
        a[i].flag = 1;
        if (Rmax < a[i].R)
            Rmax = a[i].R;
    }
    temp = 2 * a[m - 1].RH + Rmax * Rmax;  //这里就是我莫名其妙错误的原因
    //表达式的返回值的数据类型由该表达式的最高的数据类型决定，我一开始把Rmax设置成了int
    //然后死活error

    qsort(a, n, sizeof(COLUMN), comparR);


    for (i = 0;i < n;i++)
    {
        if (a[i].R < Rmax)
            break;
    }
    if (i == 0)
    {
        res += temp;
    }
    else
    {
        for (j = 0;j < i;j++)
        {
            if (temp1 < (a[j].R * (a[j].R + 2 * a[j].H)))
                temp1 = a[j].R * (a[j].R + 2 * a[j].H);
        }
        if (temp1 < temp)
        {
            res += temp;
        }
        else
            res += temp1;
    }
    printf("%lld", res);
    return 0;
}
int compar(const void* p1, const void* p2)
{
    int flag = 0;
    long long arh, brh;
    COLUMN* a = (COLUMN*)p1, * b = (COLUMN*)p2;
    arh = a->RH;
    brh = b->RH;
    if (arh > brh)
        flag = -1;
    else
        flag = 1;
    return flag;
}
void myPrint(char* a)
{
    static int tim = 0;
    int i = 0;
    printf("case #%d:\n", tim++);
    printf("%s\n", a);
}

