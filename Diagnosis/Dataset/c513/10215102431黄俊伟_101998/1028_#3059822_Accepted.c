#include <stdio.h>
#include <stdlib.h>

char flag;

int cmp(const void* p1, const void* p2)
{
    if(flag =='A')
        return *(int*)p1 - *(int*)p2;
    else
        return *(int*)p2 - *(int*)p1;
}

int main(void)
{
    int n[100];
    int ans[100];
    int k=0,i=0;
    char c;
    flag = getchar();
    do
    {
        scanf("%d", &n[i++]);
    } while((c = getchar()) != '\n' );

    qsort(n,i,sizeof(int),cmp);

    for (int j = 0; j < i-1; ++j)
    {
        if(n[j]!=n[j+1])
            ans[k++]=n[j];
    }
    ans[k++]=n[i-1];
    for (int j = 0; j < k; j++)
    {
        printf("%d",ans[j]);
        if(j!=k-1)
            printf(" ");
    }
    
    getchar();
    return 0;
}