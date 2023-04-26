#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1, const void* p2)
{
    return *((int*)p1) - *((int*)p2);
}

int main(void)
{
    int n,i,ans=0;
    int num[100000];
    scanf("%d",&n);getchar();
    for(i=0;i<n;++i)
    {
        scanf("%d",&num[i]);
    }
    qsort(num,n,sizeof(int),cmp);
    for(i=0;i<n;i+=2)
    {
        ans+=abs(num[i+1]-num[i]);
    }
    printf("%d\n",ans);
    system("pause");
    return 0;
}
