#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    int *a = (int*)malloc(1000005*sizeof(int));
    while(scanf("%d", &a[i]) != EOF)
        i++;
    qsort(a,i,sizeof(int),cmp);
    
    
    return 0;
}
