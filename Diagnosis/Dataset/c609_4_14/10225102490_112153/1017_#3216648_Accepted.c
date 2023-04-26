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
    char c;
    scanf("%c\n",&c);
    while ((scanf("%d",&a[i])) != EOF) i++;
    //for (int j = 1; j < i; j++)
    //{
        //printf("a=%d ",a[j]);

    //}
    //printf("\n");
    if (c == 'A') qsort(a+1,i-1,sizeof(int),cmpa);
    else qsort(a+1,i-1,sizeof(int),cmpd);
    //for (int j = 1; j < i; j++)
    //{
        //printf("a=%d ",a[j]);

    //}
    //printf("\n");
    int s[1111]={0};
    int k,j;
    s[1] = a[1];
    for (j = 2,k = 2; j <= i-1; j++)
    {
        if (a[j] == a[j-1]) continue;
        s[k] = a[j];
        //printf("s=%d a=%d ",s[k],a[j]);
        k++;
    }
    for (int p = 1; p < k; p++)
    {
        printf("%d ",s[p]);
    }
}