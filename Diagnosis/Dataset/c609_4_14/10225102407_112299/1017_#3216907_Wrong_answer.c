#include<stdio.h>
#include<stdlib.h>
int main ()
{
    int cmp_int1(const void*_a,const void *_b)
    {
        int* a = (int *) _a;
        int* b = (int *) _a;
        return *a-*b;
    }
    int cmp_int2 (const void*_a,const void *_b)
    {
        int* a = (int *) _a;
        int* b = (int *) _a;
        return *b-*a;
    }
    char a;
    int b[101]={0},k=0;
    scanf ("%c",&a);
    while (scanf ("%d",&b[k])!=EOF)
    {
        k++;
    }
    if (a=='A')
    {
        qsort(b,k,sizeof (b[0]),cmp_int1);
    }
    if (a=='D')
    {
        qsort (b,k,sizeof(b[0]),cmp_int2);
    }
    printf("%d",&b[0]);
    for (int i=1;i<k;i++)
    {
        if (b[i]!=b[i-1])
        {
            printf(" %d",b[i]);
        }

    }
    return 0;
}
