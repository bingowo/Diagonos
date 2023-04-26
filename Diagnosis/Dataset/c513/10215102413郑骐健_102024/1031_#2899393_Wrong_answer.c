#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>


int N;
int cmp(const void* p1, const void* p2)
{
    int* p_1 = (int*)p1;
    int* p_2 = (int*)p2;
    if (N)return (*p_1 > *p_2) ? 1 : -1;
    else return (*p_1 < *p_2) ? 1 : -1;
}
int main()
{
    int t;
    int i;
    scanf("%d", &t);
    for ( i = 0;i < t;i++);
    {
        int n;
        scanf("%d", &n);
        int s1[1100];
        int s2[1100];
        for (int q = 0;q < 2;q++)
        {
            for (int z = 0;z < n;z++)
            {
                if(q==0)scanf("%d", &s1[z]);
                else  scanf("%d", &s2[z]);
            }
        }
        N = 1;
        qsort(s1, n, sizeof(int), cmp);
        N = 0;
        qsort(s2, n, sizeof(int), cmp);
        int o = 0;
        for (int s = 0;s < n;s++)
        {
            o += s1[s] * s2[s];
        }
        printf("case #%d:\n%d\n", i, o);
    
    }
    
    return 0;

}
