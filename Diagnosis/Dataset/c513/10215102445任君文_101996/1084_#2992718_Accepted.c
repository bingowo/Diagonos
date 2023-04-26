#include<stdio.h>
#include<stdlib.h>
int main()
{
    char c;
    int n;
    int T;
    int res,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&n);
        res=1<<n;
        printf("case #%d:\n",i);
        printf("%d\n",res);
    }
    return 0;
}