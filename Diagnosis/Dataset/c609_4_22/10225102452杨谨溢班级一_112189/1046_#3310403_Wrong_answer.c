#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int m = 0;
int cmp(const void* a, const void* b)
{
    int* A = (int*)a;
    int* B = (int*)b;
    return *(A + m) - *(B + m);
}

int main()
{
    int T;   scanf("%d", &T);
    int n = 0; // 最终结果
    char min[105] = { 0 };   int mm = 0;  // 一共有mm个不同的字符
    int(*cot)[105] = (int(*)[105])malloc(sizeof(int[105]) * T);
    int e = 0;
    char chu[105] = { 0 };   scanf("%s", chu);
    int L = strlen(chu);
    for (int l = 0; l < L;)
    {
        int cou = 1;
        while (l < L && chu[l] == chu[l + 1])  cou++, l++;
        if (l >= L) break;
        min[mm++] = chu[l];
        cot[0][e++] = cou;
        l++;
        //printf("LLLLLLLLLLLLLLLLL\n");
    } // 一共有mm个不同的字符
    //printf("chucccccccccccccccccccccccccccccccccccccc: %s\n",min);
    int flag = 0;
    for (int s = 1; s < T; ++s)
    {
        if (flag == 1) continue;
        char str[105];
        scanf("%s", str);
        int L = strlen(str);
        e = 0;
        for (int l = 0; l < L;)
        {
            int cou = 1;
            while (l < L && str[l] == min[e] && str[l] == str[l + 1])  cou++, l++;
            if (min[e] != str[l])
            {
                //printf("%d %d    ",e,l);
                flag = 1;// 不符合
                printf("-1\n");
                break;
            }
            else if (l == L - 1 && cot[s][mm - 1] == 0)
            {
                flag = 1;// 不符合
                printf("-1\n");
                break;
            }
            else cot[s][e++] = cou;
            ++l;
        }
    }

    if (flag == 1);
    else {
        for (m = 0; m < mm; ++m)
        {
            qsort(cot, T, sizeof(cot[0]), cmp);

            int w = T % 2;
            int sum = 0;
            if (w == 1)
            {
                w = T / 2;
                for (int i = 0; i < T; ++i)  
                    sum = sum + abs(cot[i][m] - cot[w][m]);
            }
            else
            {
                w = T / 2;
                w = cot[w][m] + cot[w - 1][m];
                if (w % 2 == 0) w /= 2;
                else w = cot[T/2][m];
                for (int i = 0; i < T; ++i)  
                    sum = sum + abs(cot[i][m] - w);
            }
            //printf("LLLLLLLLLLLLLLLLL\n");
            n += sum;
        }
        printf("%d\n", n);
    }
    free(cot);
    return 0;
}
