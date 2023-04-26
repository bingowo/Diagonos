#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    char judge_;
    int L[1001];
    scanf("%c", &judge_);
    int n, num_L, m_1, z,middle, n_1, max;
    num_L = 0;
    while (scanf("%d", &L[num_L]) != EOF) { num_L++; }
    if (judge_ == 'A')
    {
        for (m_1 = 0;m_1 < num_L - 1;m_1++)
        {
            for (z = 0;z < num_L - m_1 - 1;z++)
            {
                if (L[z] > L[z + 1])
                {
                    middle = L[z], L[z] = L[z + 1], L[z + 1] = middle;
                }
            }
        }
    }
    else
    {
        for (m_1 = 0;m_1 < num_L - 1;m_1++)
        {
            for (z = 0;z < num_L - m_1 - 1;z++)
            {
                if (L[z] < L[z + 1])
                {
                    middle = L[z], L[z] = L[z + 1], L[z + 1] = middle;
                }
            }
        }
    }
    printf("%d", L[0]);
    for (n = 1;n < num_L;n++)
    {
        if (L[n] != L[n - 1])
        {
            printf(" %d", L[n]);
        }
        }
    return 0;
}