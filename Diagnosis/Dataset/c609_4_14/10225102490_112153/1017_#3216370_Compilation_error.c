#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmpa (const void *a, const void *b)
{
    if (*(int*)a > *(int*)b) return 1;
    else return -1;
    //return *(int *)a - *(int *)b;
}
int cmpd(const void *a, const void *b)
{
    if (*(int*)a > *(int*)b) return -1;
    else return 1;
    //return *(int *)b - *(int *)a;
}

int main()
{
    int a[1111];
    int i = 1;
    char j;
    scanf("%c",&j);
    while ((scanf("%d",&a[i])) != EOF) i++;
    if (j == 'A') qsort(a+1,1110,sizeof(int),cmpa);
    else qsort(a+1,i-1,sizeof(int),cmpd);
    int s[1111];
    int k,j;
    for (j = 1,k = 1; j <= i-1; j++)
    {
        if (a[j] == a[j-1]) continue;
        s[k] = a[j];
        k++;
    }
    for (int i = 1; i < k; i++)
    {
        printf("%d",s[k]);
    }
}