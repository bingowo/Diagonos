#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int primetable[26] = { 1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 };
int createarray(int* a, char* A);
void addplus(int a, int* res);
int multiplus(int p, int* res);
int main()
{
    char A[300];
    int a[30], res[100], lena, lenres=0, temp,i;
    scanf("%s", A);
    lena = createarray(a, A);
    memset(res, 0, sizeof(res));
    for (i = lena - 1;i >= 0;i--)           //从大到小是--，编译器还不给你debug，就过分
    {
        //res = (res + a[i]) * primetable[i];       //第n个元素的值要乘遍前n-1个素数
        addplus(a[i], res);
        //lenres = multiplus(primetable[i], res);     //由于后面可能没有进位，所以返回值可能比上一次的更小
        temp = multiplus(primetable[i], res);
        if (temp > lenres) lenres = temp;
    }
    for (i = lenres - 1;i >= 0;i--)
        printf("%d", res[i]);


    return 0;
}
int createarray(int* a, char* A)
{
    int temp = 0, i = 0;
    char* head, * tail, * p;
    tail = A + strlen(A) - 1;
    head = tail + 1;
    while (tail >= A)
    {
        if (tail == A)
        {
            tail--;
            p = tail + 1;
            while (p != head)
            {
                temp = temp * 10 + *p - '0';
                p++;
            }
        }
        else if (*tail != ',')
        {
            tail--;
            continue;
        }
        else if (*tail == ',')
        {
            p = tail + 1;
            while (p != head)
            {
                temp = temp * 10 + *p - '0';
                p++;
            }
            head = tail;
            tail--;
        }

        a[i++] = temp;
        temp = 0;
    }
    return i;     //就是a中的有效长度
}
void addplus(int a, int* res)
{
    int i = 0;
    res[0] += a;
    while (res[i] >= 10)
    {
        res[i + 1] += res[i] / 10;
        res[i] = res[i] % 10;
        i++;
    }
}
int multiplus(int p, int* res)
{
    int i = 0, lenres;
    while (res[i] != 0)
    {
        res[i] *= p;
        i++;
    }
    i = 0;
    while (res[i] >= 10)
    {
        res[i + 1] += res[i] / 10;
        res[i] = res[i] % 10;
        i++;
    }
    if (res[i] == 0)
        lenres = i;
    else
        lenres = i+1;
    return lenres;
}
