#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        char info[61] = "\0";

        scanf("%s", info);

        int table[256];

        for (int j = 0;  j < 256; j++)
        {
            table[j] = -1;
        }
        table[info[0]] = 1;
        int flag = 1;
        int R = 1;
        int length = strlen (info);
        for (int j = 1; j < length; j++)
        {
            if (table[info[j]] == -1)
            {
                if (flag)
                {
                    table[info[j]] = 0;
                    flag = 0;
                    R++;
                }
                else
                {
                    table[info[j]] = R++;
                }
            }
        }

        if (R == 1)
        {
            R = 2;
        }

        long long answer = 1;

        for (int j = 1; j < length; j++)
        {
            answer = answer*R + table[info[j]];
        }

        printf("case #%d:\n%lld\n", i, answer);
    }

    return 0;
}