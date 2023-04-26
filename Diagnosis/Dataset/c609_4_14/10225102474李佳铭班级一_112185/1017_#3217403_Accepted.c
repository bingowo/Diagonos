#include <stdio.h>
#include <stdlib.h>

int cmp1(void* a,void*b)
{
    int A = *(int*)a;
    int B = *(int*)b;
    if(A != B)
        return A - B;
    else
        return 1;
}

int cmp2(void* a,void*b)
{
    int A = *(int*)a;
    int B = *(int*)b;
    if(A != B)
        return B - A;
    else
        return 1;
}

int main()
{
    char n;
    int s;
    scanf("%c",&n);
    int a[100];
    int i = 0;
    while(scanf("%d",&a[i]) != EOF)
        i++;
    s = sizeof(a)/sizeof(a[0]);
    if(n == 'A')
        qsort(a,i,sizeof(a[0]),cmp1);
    else
        qsort(a,i,sizeof(a[0]),cmp2);

        for(int j = 0;j < i;j++)
        {
            if(a[j] != a[j+1])
                printf("%d ",a[j]);
        }

}

