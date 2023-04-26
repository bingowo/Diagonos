#include <stdio.h>
#include <stdlib.h>

#define OUT 0
#define MAYIN 1
#define NINENINE 2
#define NINEEIGHTNINE 3
#define REPETITION 1

int main()
{
    short T;
    struct bigint
    {
        int cnt;
        int v[1000];
    };
    scanf("%hd", &T);
    getchar();
    for (int i = 0;i < T;i++)
    {
        bigint n={0,{0}};
        int specialbeginend[100][2];
        char c = 0;
        int state = OUT,k=0,kk=0;
        scanf("%c", &c);
        while (c!='\n')
        {
            n.cnt++;
            n.v[n.cnt] = c - '0';
            scanf("%c", &c);
        }
        for (int j = 1,iseight=1;j <= n.cnt+1;j++)
        {
            switch (state)
            {
            case OUT:
                if (n.v[j] == 9)
                    state = MAYIN;
                break;
            case MAYIN:
                if (n.v[j] == 9)
                {
                    state = NINENINE;
                    specialbeginend[k][0] = j - 1;
                }
                else if (n.v[j] == 8)
                {
                    state = NINEEIGHTNINE;
                    specialbeginend[k][0] = j - 1;
                }
                break;
            case NINENINE:
                if (n.v[j] != 9)
                    if (n.v[j] == 8)
                        state = NINEEIGHTNINE;
                    else
                    {
                        state = OUT;
                        specialbeginend[k++][1] = j - 1;
                    }
                break;
            case NINEEIGHTNINE:
                if (n.v[j] == 9)
                    iseight = 0;
                else if (!iseight && n.v[j] == 8)
                    iseight = 1;
                else
                {
                    state = OUT;
                    specialbeginend[k++][1] = j - 1;
                }
                break;
            default:
                printf("wrong state\n");
                break;
            }
        }
        for (int j = 0;j < k;j++)
        {
            int end = specialbeginend[j][1];
            n.v[specialbeginend[j][0] - 1] += 1;
            for (int l = specialbeginend[j][0], crisscross = 0;l <= end;l++)
            {
                n.v[l] = crisscross;
                if (crisscross)
                    crisscross = 0;
                else
                    crisscross = 1;
            }
        }
        kk = k;
        for(int j=1;j<=n.cnt;j++)
            switch (state)
            {
            case OUT:
                if (n.v[j] == n.v[j - 1])
                {
                    state = REPETITION;
                    specialbeginend[k++][1] = j ;
                }
                break;
            case REPETITION:
                if (n.v[j] != n.v[j - 1])
                    state = OUT;
                break;
            default:
                printf("wrong state\n");
                break;
            }
        for (int j = kk;j < k;j++)
        {
            int end = specialbeginend[j][1],crisscross=1;
            n.v[end++]++;
            n.v[end] = 0;
            while (n.v[end++] == n.v[end]&& end <= n.cnt)
            {
                n.v[end] = crisscross;
                if (crisscross)
                    crisscross = 0;
                else
                    crisscross = 1;
            }
        }
        if (++n.v[n.cnt] == n.v[n.cnt - 1] && !k)
            n.v[n.cnt]++;
        else if (k)
            n.v[n.cnt]--;
        if (n.v[0] == 0)
            k = 1;
        else
            k = 0;
        printf("case #%d:\n", i);
        for (int j = k;j <=n.cnt;j++)
            printf("%d", n.v[j]);
        printf("\n");
    }
    return 0;
}
