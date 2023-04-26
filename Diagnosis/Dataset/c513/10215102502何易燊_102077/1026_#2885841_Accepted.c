#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
    return *(int*)a-*(int*)b;
}

main()
{
    int n;
    scanf("%d",&n);
    int sum = 0;
    int *p = (int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++) scanf("%d",&p[i]);
    qsort(p,n,sizeof(p[0]),cmp);
    for (int i=0;i<n;i+=2)
    {
        sum += (p[i]-p[i+1]>=0)? p[i]-p[i+1] : p[i+1]-p[i];
    }
    printf("%d\n",sum);
    system("pause");
    return 0;
}