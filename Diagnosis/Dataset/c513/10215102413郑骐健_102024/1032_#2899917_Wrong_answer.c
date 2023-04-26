#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void* p1, const void* p2)
{
    int* p_1 = (int*)p1;
    int* p_2 = (int*)p2;
    while (*p_1 == *p_2)
    {
        if (p_1[0] == -1)return -1;
        p_1++;
        p_2++;
    }
    return (p_1[0] > p_2[0]) ? -1 : 1;
    
}
int s[1000][50];
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0;i < t;i++)
    {
        int z;
        scanf("%d", &z);
        for (int m = 0;m < z;m++)
        {
            int r;
            int point = 0;
            do
            {
                scanf("%d", &r);
                s[m][point++] = r;
            } while (r != -1);
        }
        qsort(s, z, sizeof(int) * 50, cmp);
        for (int a = 0;a < z;a++)
        {
            int point2 = 0;
            while (s[a][point2] != -1)
            {
                
                printf("%d ",s[a][point2++]);
            }
            printf("\n");
        }
    }
    
        return 0;

}
