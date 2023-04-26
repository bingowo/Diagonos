#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int primetable[26] = { 0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 };
int createarray(int* a, char* A);
int Max(int a, int b) { return a > b ? a : b; }

void myPrint(int* res, int len);
int main()
{
    int T, i, j, sum, up, lena, lenb, lenres;
    char A[80], B[80];
    int a[30], b[30], res[30];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));

    scanf("%d", &T);
    while (T--)
    {
        up = 0;
        j = 0;
        scanf("%s", A);scanf("%s", B);
        lena = createarray(a, A);
        lenb = createarray(b, B);
        lenres = Max(lena, lenb);
        for (i = 1;i <= lenres;i++)       //
        {
            sum = a[i] + b[i];
            if (sum >= primetable[i])
            {
                sum = sum - primetable[i];
                up = 1;
            }
            else
            {
                up = 0;
            }
            res[j++] = sum;
            sum = 0;
        }
        if (up == 1)
        {
            res[j++] = up;
            lenres++;
        }
        myPrint(res, lenres);
    }
    return 0;
}


int createarray(int* a, char* A)
{
    int temp = 0, i = 1;
    char* head, * tail, * p;
    tail = A + strlen(A) - 1;
    head = tail + 1;
    while (tail >= A)
    {
        if (tail == A)
        {
            tail--;
            p = head - 1;
            while (p != tail)
            {
                temp = temp * 10 + *p - '0';
                p--;
            }
        }
        else if (*tail != ',')
        {
            tail--;
            continue;
        }
        else if (*tail == ',')
        {
            p = head - 1;
            while (p != tail)
            {
                temp = temp * 10 + *p - '0';
                p--;
            }
            head = tail;
            tail--;
        }
        
        a[i++] = temp;
        temp = 0;
    }
    return i - 1;     //就是a中的有效长度
}
void myPrint(int* res, int len)
{
    static int i = 0;
    int len1;
    printf("case #%d:\n", i);
    len1 = len - 1;
    while (len1 >= 0)
    {
        printf("%d", res[len1]);
        if (len1 != 0)
            printf(",");
        len1--;
    }
    printf("\n");
    i++;
}

