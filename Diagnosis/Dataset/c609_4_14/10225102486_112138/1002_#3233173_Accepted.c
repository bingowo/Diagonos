#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int n;
        scanf("%d", &n);

        int sum = 0, len[100];
        do
        {
            len[sum++] = n % 2;
            n /= 2;
        } while (n);

        int cnt = 0;
        int changdu = 1;
        for (int j = sum; j > 0; j--)
        {
            if (len[j] == len[j - 1])
            {
                cnt = 1;
                continue;
            }
            else if (len[j] != len[j - 1])
                cnt++;

            if (cnt > changdu)
                changdu = cnt;
        }

        printf("case #%d:\n%d", i, changdu);
        printf("\n");
    }
    system("pause");
    return 0;
}