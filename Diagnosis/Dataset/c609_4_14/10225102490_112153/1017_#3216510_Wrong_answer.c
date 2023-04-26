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


int a[1111] = {0};
int main()
{
    int i = 0;
    char c;
    scanf("%c",&c);
    while ((scanf("%d",&a[i])) != EOF) i++;
    for (int p = 0; p < i; p++)
    {
        printf("a=%d ",a[i]);
    }
    printf("\n");
    if (c == 'A') qsort(a,i-1,sizeof(int),cmpa);
    else qsort(a,i-1,sizeof(int),cmpd);
    int s[1111];
    int k,j;
    for (j = 0,k = 0; j <= i-1; j++)
    {
        if (a[j] == a[j-1]) continue;
        s[k] = a[j];
        k++;
    }
    for (int i = 0; i < k; i++)
    {
        printf("%d",s[k]);
    }
}