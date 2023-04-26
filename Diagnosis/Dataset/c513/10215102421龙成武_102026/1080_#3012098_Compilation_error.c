#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void div(int* a)  //只能除2的简易大数字除法器
{
    int i = 101, carry = 0;
    while (a[i] == 0 && i >= 0) i--;  //去除前导零
    //当只有一位，且值为1的时候，这个给下一位的carry会被舍弃掉
    for (;i > -1;i--)
    {
        a[i] += carry * 10;
        carry = a[i] % 2;      //当前这一位除以2后余下来的值会继续留到下一位进行运算,只可能是1或者0
        a[i] /= 2;             
    //因为这里每一位都直接/2，对最后一位也是，所以最后一为是1还是0，最后得到的都一样，所以需要在函数外对余数进行处理
        //呃，但既然都一样了，其实不处理也行
    }
}
int main()
{
    int i, T, x, len, a[101], lena, lenans, count[200], ans[500];
    char s[101];
    scanf("%d", &T);
    for (x = 0;x < T;x++)
    {
        printf("case #%d:\n", x);
        scanf("%s", s);
        len = strlen(s);
        lenans = 0;
        memset(a, 0, sizeof(a));
        for (i = 0;i < len;i++)
            a[i] = s[len - 1 - i]-'0';
        lena = len - 1;
        while (lena >= 0)
        {
            if (a[0] % 2 == 0)
                ans[lenans++] = 0;
            else
            {
                ans[lenans++] = 1;//a[0]--;
            }
            div(a);
            while (a[lena] == 0 && lena >= 0) lena--;   //得到的是首非零元的下标,到-1就停了
        }
        ans[lenans] = 0;
        int first = 0;
        memset(count, 0, sizeof(count));
        while (ans[first] == 0 && first < lenans - 1) first++;
        for (i = first;i < lenans ;i++)
        {
            int j, carry;
            for (j = 0;j < 200;j++)
                count[j] *= 2;
            count[0] += ans[i];
            for (j = 0;j < 200;j++)
            {
                count[j + 1] += count[j] / 10;
                count[j] %= 10;
            }
        }
        i = 199;
        while (count[i] == 0 && i > -1)  i--;
        if (i == -1) printf("0");
        for (;i > -1;i--)
            printf("%d", count[i]);
        printf("\n");
    }
    return 0;
}
