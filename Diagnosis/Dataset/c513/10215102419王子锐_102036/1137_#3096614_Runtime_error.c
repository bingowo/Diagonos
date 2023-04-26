#include <stdio.h>
#include <string.h>
char* addBigInt(char aNum1[],char aNum2[], char aRst[], int iLen)
{
    memset(aRst, '0', iLen + 1);  //将aRst的每位初始化为0，预留最高位位置，开一个长度大1的数组
    aRst[iLen + 1] = '\0';
    for (int i = iLen; i >0; i--)
    {
        aRst[i] += (aNum1[i-1]-'0');  //逐位相加
        aRst[i] += (aNum2[i-1]-'0');
        if (aRst[i] > '9')
        {
            aRst[i] -= 10;
            aRst[i - 1]++;    //进位
        }

    } // end of for
    if (aRst[0] == '1') return aRst;//若最高位相加需要进位，则返回首位地址
    else return aRst + 1;           //若最高位相加不需进位，首位为0，则返回第二位地址
}
int cmp(char* aNum, char* bNum)  //比较绝对值大小
{
    char a[1000] , b[1000];
    strcpy(a, aNum);
    strcpy(b, bNum);
    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] == '-')
        {
            a[i] = '0';
            return strcmp(a, b);
        }
        if (b[i] == '-')
        {
            b[i] = '0';
            if(strcmp(a, b)==0)return 0;
            if (strcmp(b, a) == 1)return 2;
            if (strcmp(b, a) == -1)return -2;
        }
    }
}
char* minusBigInt(char aNum1[], char aNum2[], char aRst[], int iLen)
{
    memset(aRst, '0', iLen);  //将aRst的每位初始化为0，预留最高位位置，开一个长度大1的数组
    aRst[iLen] = '\0';
    switch (cmp(aNum1, aNum2))
    {
    case 0:
        aRst[1] = '\0';
        return aRst;
        break;
    case 1:                     //a绝对值大且为负
        for (int i = iLen-1; i > 0; i--)
        {
            aRst[i] = aNum1[i];  //逐位相减
            aRst[i] -= aNum2[i];
            aRst[i] += '0';
            if (aRst[i] < '0')
            {
                aRst[i] += 10;
                aNum1[i - 1]--;    //借位
            }
        } // end of for
        for (int i = 0; i < iLen; i++)
        {
            if (aRst[i] != '0')
            {
                aRst[i - 1] = '-';   //必定为负，所以给加和添上负号
                return (aRst + i-1);
            }
        }
        break;

    case -1:
        for (int i = iLen-1; i >=0; i--)
        {                      //a绝对值小且为负
            if (aNum1[i] == '-') { aNum1[i] = '0'; }
            aRst[i] = aNum2[i];  //逐位相减
            aRst[i] -= aNum1[i];
            aRst[i] +='0';
            if (aRst[i] < '0') {
                aRst[i] += 10;
                aNum2[i - 1]--;    //借位
            }
        } // end of for
        for (int i = 0; i < iLen; i++)
        {
            if (aRst[i] != '0')
            {
                return (aRst + i);  //    去掉多余的0
            }
        }
        break;
    case 2:
        for (int i = iLen-1; i > 0; i--)
        {
            aRst[i] = aNum2[i];  //逐位相减
            aRst[i] -= aNum1[i];
            aRst[i] +='0';
            if (aRst[i] < '0')
            {
                aRst[i] += 10;
                aNum2[i - 1]--;    //借位
            }
        } // end of for
        for (int i = 0; i < iLen; i++)
        {
            if (aRst[i] != '0')
            {
                if (aRst[i] != '0')
                {
                    aRst[i - 1] = '-';
                    return (aRst + i - 1);
                }
            }
        }
        break;

    case -2:
        for (int i = iLen-1; i >= 0; i--)
        {
            if (aNum2[i] == '-') { aNum2[i] = '0'; }
            aRst[i] = aNum1[i];  //逐位相减
            aRst[i] -= aNum2[i];
            aRst[i] +='0';
            if (aRst[i] < '0')
            {
                aRst[i] += 10;
                aNum1[i - 1]--;    //借位
            }
        } // end of for
        for (int i = 0; i < iLen; i++)
        {
            if (aRst[i] != '0')
            {
                return (aRst + i);
            }
        }
        break;
    }
}
int* samelength(char* a, char* b)  //将两个字符串化为同长度，并将较小的空位赋值0
{
    if (a[0] == '-'&& b[0] == '-') //若同时为负数，则去掉符号
    {
        for (int i = 0; a[i] != '\0'; i++)
        {
            a[i] = a[i + 1];
        }
        for (int i = 0; b[i] != '\0'; i++)
        {
            b[i] = b[i + 1];
        }
    }
    int na = strlen(a), nb = strlen(b);
    char temp[1000] ;
    if (na>=nb)
    {
        strcpy(temp, b);            //存下较小数组的值
        memset(b,'0', strlen(a));   //将较小数字的所有位数赋0
        strcpy(b + na - nb, temp);  //化为相同长度
        return na;                 //返回长度较大的数字位数
    }
    if (na < nb)
    {
        strcpy(temp, a);
        memset(a, '0', strlen(b));
        strcpy(a + nb - na, temp);
        return nb;
    }
}

int main()
{
    char a[1000] , b[1000] , arst[1000];
    while (scanf("%s %s", a, b) != EOF)     //返回值控制输入次数
    {
        if ((a[0] != '-' && b[0] == '-') || (a[0] == '-' && b[0] != '-'))    //分类讨论加数的正负性
        {
            printf("%s\n", minusBigInt(a, b, arst, samelength(a, b))); continue;
        }
        if (a[0] == '-' && b[0] == '-')
        {
            printf("-%s\n", addBigInt(a, b, arst, samelength(a, b))); continue;
        }
        if (a[0] != '-' && b[0] != '-')
        {
            printf("%s\n", addBigInt(a, b, arst, samelength(a, b))); continue;
        }
        return 0;
    }
}


