#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int primetable[26] = { 1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 };
int createarray(int* a, char* A);
int addplus(int a, int* res,int lenres);
int multiplus(int p, int* res,int lenres);
int main()
{
    char A[300];
    int a[30], res[100], lena, lenres=1, temp1,temp2,i;
    scanf("%s", A);
    lena = createarray(a, A);
    memset(res, 0, sizeof(res));
    for (i = lena - 1;i >= 0;i--)           //从大到小是--，编译器还不给你debug，就过分
    {
        //res = (res + a[i]) * primetable[i];       //第n个元素的值要乘遍前n-1个素数
        temp1=addplus(a[i], res,lenres);
        if (temp1 > lenres)    lenres = temp1;
        //lenres = multiplus(primetable[i], res);     //由于后面可能没有进位，所以返回值可能比上一次的更小
        temp2 = multiplus(primetable[i], res,lenres);
        if (temp2 > lenres) lenres = temp2;
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
int addplus(int a, int* res,int lenres)
{
    int i = 0,temp1;
    res[0] += a;
    //while (res[i] >= 10)        想了想，这个还是不完全可靠，还是依照高精度乘法里的去整
    while(i<lenres||res[i]>=10)
    {
        if (res[i] >= 10)
        {
            res[i + 1] += res[i] / 10;
            res[i] = res[i] % 10;
        }
        i++;
    }
    if (res[i] == 0)     
        temp1 = i;
    else
        temp1 = i + 1;
    return temp1;
}
int multiplus(int p, int* res,int lenres)
{
    int i = 0, temp2;
    //while (res[i] != 0)                         //这个条件判断是不对的呀，因为中间也可能有0，会导致中途退出的
    while(i<lenres)
    {
        res[i] *= p;
        i++;
    }
    i = 0;                                      //据余钒所说，必须要分开进行这俩while
    //while (res[i] >= 10)                    //中间也可能有断层的，某一位不大于10，但后来的大
    while(i<lenres||res[i]>=10)                 //这个or也很重要，因为有可能在最高位有多个进位
    {
        if (res[i] >= 10)
        {
            res[i + 1] += res[i] / 10;
            res[i] = res[i] % 10;
        }
        i++;
    }
    if (res[i] == 0)                //如果在最后一次while循环里的res[i]>=10的话，那么就说明有进位，那么res[i]就是有效元素（else），不然就是无效元素（if），
        temp2 = i;
    else
        temp2 = i+1;
    return temp2;
}
