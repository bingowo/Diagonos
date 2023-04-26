#include <stdio.h>
#include <stdlib.h>

#define OUT 0
#define MAYIN 1
#define NINENINE 2
#define NINEEIGHT 3
#define REPETITION 4

int main()
{
    short T;
    struct bigint
    {
        int cnt;
        int v[1000];
    };
    scanf_s("%hd", &T);
    getchar();
    for (int i = 0;i < T;i++)
    {
        bigint n={0,{0}};
        int k = 0, state = OUT;
        char c = 0;
        scanf_s("%c", &c);
        while (c!='\n')
        {
            n.cnt++;
            n.v[n.cnt] = c - '0';
            scanf_s("%c", &c);
        }
        n.cnt++;
        for (int j = 1;j <= n.cnt&&(state==OUT||state==MAYIN);j++)
        {
            switch (state)
            {
            case OUT:
                if (n.v[j] == 9)
                    state = MAYIN;
                if (n.v[j] == n.v[j - 1])
                {
                    state = REPETITION;
                    k = j;
                }
                break;
            case MAYIN:
                if (n.v[j] == 9)
                {
                    state = NINENINE;
                    k = j - 1;
                }
                else if (n.v[j] == 8)
                {
                    state = NINEEIGHT;
                    k = j - 1;
                }
                else
                    state = OUT;
                break;
            default:
                printf("wrong state\n");
                break;
            }
        }
        if(state==REPETITION)
        {
            n.v[k]++;
            for (int j = k+1, crisscross = 0;j <= n.cnt;j++)
            {
                n.v[j] = crisscross;
                if (crisscross)
                    crisscross = 0;
                else
                    crisscross = 1;
            }
        }
        if(state==NINENINE||state==NINEEIGHT)
        {
            if (++n.v[k - 1] == n.v[k - 2])
                n.v[k - 1]++;
            for (int j = k, crisscross = 0;j <= n.cnt;j++)
            {
                n.v[j] = crisscross;
                if (crisscross)
                    crisscross = 0;
                else
                    crisscross = 1;
            }
        }
        if (state == OUT)
        {
            if (++n.v[n.cnt-1] == n.v[n.cnt - 2])
                n.v[n.cnt-1]++;
        }
        if (state == MAYIN)
        {
            n.v[n.cnt - 1] = 0;
            if (++n.v[n.cnt - 2] == n.v[n.cnt - 3])
                n.v[n.cnt-2]++;
        }
        if (n.v[0] == 0)
            k = 1;
        else
            k = 0;
        printf("case #%d:\n", i);
        for (int j = k;j <n.cnt;j++)
            printf("%d", n.v[j]);
        printf("\n");
    }
    return 0;
}