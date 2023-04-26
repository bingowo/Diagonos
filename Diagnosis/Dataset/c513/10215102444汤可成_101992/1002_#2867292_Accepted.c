#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
   int T = 0;
    scanf("%d", &T);
    int i = 0;
    for (i = 0; i < T; i++)
    {
        long long int ret = 0;
        int num = 0;
        int arr[123];
        int q = 0;
        while (q < 123)
        {
            arr[q] = -1;
            q++;
        }
        char s[60] = { 0 };
        scanf("%s", s);
        int j = 0;
        while (s[j] != 0)
        {
            if (arr[s[j]] == -1)
            {
                if (num == 0)
                {
                    arr[s[j]] = 1;
                    num++;
                }
                else
                {
                    if (num == 1) arr[s[j]] = 0;
                    else arr[s[j]] = num;
                    num++;
                }
            }
            j++;
        }
        if (num == 1) num++;
        int p = 0;
        for (p = 0; p < j; p++)
        {
            ret = ret * num + arr[s[p]];
        }
        printf("case #%d:\n", i);
        printf("%lld\n", ret);

    }

    return 0;
}