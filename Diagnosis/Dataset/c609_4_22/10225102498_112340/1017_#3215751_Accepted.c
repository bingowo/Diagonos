#include <stdio.h>
#include <stdlib.h>

int cmpa(void* a, void* b)
{
    int m = *(int*)a, n = *(int*)b;
    return m-n;
}

int cmpd(void* a, void* b)
{
    int m = *(int*)a, n = *(int*)b;
    return n-m;
}

int main()
{
    char c;
    int i = 0;
    scanf("%c", &c);
    int num[105];
    while(scanf("%d", &num[i]) != EOF)
        i++;
    if(c == 'A')
        qsort(num, i, sizeof(int), cmpa);
    if(c == 'D')
        qsort(num, i, sizeof(int), cmpd);

    printf("%d ", num[0]);
    for(int j=1; j<i; j++)
    {
        if(num[j] !=  num[j-1])
            printf("%d ", num[j]);
    }
        
    return 0;
}
