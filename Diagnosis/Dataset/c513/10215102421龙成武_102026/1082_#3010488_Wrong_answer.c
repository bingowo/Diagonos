#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct
{
    int num[1000];           //使用时一定要记得申请空间，以及各位全赋值为0
    int sign;
    int digit;
}BIGINT, * pBIGINT;
int mymax(int a, int b)
{
    return a > b ? a : b;
}
void BigIntTrim(pBIGINT a)
{
    int i;
    for (i = 0;i < a->digit;i++)
    {
        a->num[i + 1] += a->num[i] / 10;
        a->num[i] %= 10;
    }
    for (i = a->digit;i > 0;i--)
    {
        if (a->num[i] != 0)
            break;
    }
    a->digit = i + 1;
}
void BigIntAdd(pBIGINT num1, pBIGINT num2, pBIGINT res)
{
    int i;
    res->sign = num1->sign;   //保存符号
    for (i = 0;i < mymax(num1->digit, num2->digit);i++)
    {
        res->num[i] = num1->num[i] + num2->num[i];
    }
    res->digit = num1->digit + num2->digit;
    BigIntTrim(res);
}
int main()
{
    char A[501], B[501];
    int N, lena, lenb, i, j;
    BIGINT num1, num2, res, fnum1, fnum2, fres;
    scanf("%s%s%d", A, B, &N);
    memset(&num1, 0, sizeof(num1));memset(&num2, 0, sizeof(num2));memset(&res, 0, sizeof(res));
    memset(&fnum1, 0, sizeof(fnum1));memset(&fnum2, 0, sizeof(fnum2));memset(&fres, 0, sizeof(fres));
    lena = strlen(A);
    lenb = strlen(B);
    if (strchr(A, '.') == NULL)
    {
        A[lena] = '.';
        A[lena + 1] = 0;
        //A[lena + 2] = 0;
        lena += 1;
    }
    if (strchr(B, '.') == NULL)
    {
        B[lenb] = '.';
        B[lenb + 1] = 0;
        lenb += 1;
    }
    for (i = lena;A[i] != '.';i--);
    for (j = lenb;B[j] != '.';j--);
    if ((lena - i - 1) < (lenb - j - 1))           //A的小数点位数比B的少
        fnum1.digit += (lenb - j - 1) - (lena - i - 1);
    else
        fnum2.digit += (lena - i - 1) - (lenb - j - 1);
    for (i = lena-1;i > -1;i--)
    {
        if (A[i] == '.') break;
        else
        {
            fnum1.num[fnum1.digit++] = A[i]-'0';
        }
    }
    for (i--;i > -1;i--)
    {
        num1.num[num1.digit++] = A[i] - '0';
    }
    for (j = lenb-1;j > -1;j--)
    {
        if (B[j] == '.') break;
        else fnum2.num[fnum2.digit++] = B[j] - '0';
    }
    for (j--;j > -1;j--)
    {
        num2.num[num2.digit++] = B[j] - '0';
    }
    BigIntAdd(&fnum1, &fnum2, &fres);
    //对浮点数还有四舍五入，万恶的题目,放到进位后再四舍五入好了

    if (fres.digit > fnum1.digit)    //有进位,但也最多就一个进位
    {
        res.digit = 1;
        res.num[0] = fres.num[--fres.digit];      //这里必须是前缀自减，因为digit位原本是没有东西的
        fres.num[fres.digit] = 0;
    }
    if (fres.digit >= N + 1)            //处理四舍五入
    {
        i = fres.digit - N - 1;
        if (fres.num[i] >= 5)
        {
            fres.num[i] = 0;
            fres.num[i + 1] ++;
        }
        fres.digit++;
        BigIntTrim(&fres);
    }
    if (fres.digit > fnum1.digit)    //再处理一次进位
    {
        res.digit = 1;
        res.num[0] += fres.num[--fres.digit];      
        fres.num[fres.digit] = 0;
    }
    BigIntAdd(&num1, &res, &num1);
    BigIntAdd(&num1, &num2, &res);

    if (res.digit == 0)
        printf("0");
    for (i = res.digit-1;i > -1;i--)
    {
        printf("%d", res.num[i]);
    }
    printf(".");
    for (i = fres.digit-1;N > 0;N--, i--)
    {
        if (i < 0)
            printf("0");
        else
            printf("%d", fres.num[i]);
    }
    return 0;
}
