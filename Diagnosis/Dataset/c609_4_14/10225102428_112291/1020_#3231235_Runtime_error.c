#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getNum(char s[40])
{
    int len = sizeof(s);
    int flag = 0, sum = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            sum = 10 * sum + s[i] - '0';
            flag = 1;//has a number
        }
    }
    if (flag == 0) sum = -1;//has no number
    return sum;
}

int strnumcmp(char a, char b)
{
    int num1 = getNum(a), num2 = getNum(b);
    if (num1 == num2) return a < b;
    else
    {
        if (num1 < num2) return -1;
        else return 1;
    }
}

int main()
{
    char s[120];
    int cnt = 0;
    while (scanf("%c",s[cnt])!=EOF)
    {
        cnt++;
        //getchar();
    }
    qsort(s,cnt,sizeof(char),strnumcmp);
    //cout << cnt << endl;
    for (int i = 0; i < cnt-1; i++)printf("%c%c",s[i],i!=cnt-2?' ':'\n');
}


