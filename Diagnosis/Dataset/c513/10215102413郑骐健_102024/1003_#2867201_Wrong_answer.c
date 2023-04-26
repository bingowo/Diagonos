#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void* p1, const void* p2)
{
    return  (*((long long int*)p1 + 1) < (*((long long int*)p2 + 1))) ? 1 : -1;
}
int main()
{
    int T,i;
    scanf("%d", &T);
    for (i = 0;i < T;i++)
    {
        int N;
        scanf("%d", &N);
        long long int* p = malloc(sizeof(long long int) * 20000);
        long long int* p_num = p;
        for (int j = 0;j < N;j++)
        {
            scanf("%lld", p_num);
            long long int z = 1;
            int j = 0, k = 0;
            while (k < 64)
            {
                if ((z << k)&(*p_num))
                {
                    j++;
                }
                k++;
            }
            *(p_num + 1) = j;
            p_num += 2;
        }
        
        qsort(p, (p_num - p)/2, sizeof(long long int) * 2, cmp);
        long long int* p2 = p;
        for (int j = 0;j < N;j++)
        {
            printf("%lld ", *p2);
            p2 += 2;
        }
        printf("\n");
        free(p);

    }
    return 0;

}
