#include <stdio.h>
#include <stdlib.h>

int count(int a)
{
    int sum = 1;
    if(a < 0)
    {
        a = -a;
        sum++;
    }
    while(a /= 2)
    {
        sum++;
    }
    return sum;

}
int cmp(void*a,void*b)
{
    int A = *(int*)a;
    int B = *(int*)b;
    if(count(A) != count(B))
        return count(B) - count(A);
    else
    {
        return A - B;
    }
}

int main()
{
    int a[10000];
    int i = 0;
    while(scanf("%d",&a[i]) != EOF);
    qsort(a,i,sizeof(a[0]),cmp);

    for(int j = 0;j < i; j++)
    {
        printf("%d ",a[j]);
    }
    return 0;
}
