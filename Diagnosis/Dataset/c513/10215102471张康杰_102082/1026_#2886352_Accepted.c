#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{
    return *(int*)a - *(int*)b;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    int input[n];
    for(i = 0;i < n;i++)
        scanf("%d",&input[i]);
    qsort(input,n,sizeof(int),cmp);
    int min = 0;
    for(i = 0;i < n;i += 2)
    {
        min += input[i+1] - input[i];
    }
    printf("%d\n",min);
    return 0;
}
