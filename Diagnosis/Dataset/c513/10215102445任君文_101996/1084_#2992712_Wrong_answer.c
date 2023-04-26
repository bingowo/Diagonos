#include<stdio.h>
#include<stdlib.h>
int main()
{
    char c;
    int n;
    int T;
    int res=1,i=0;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&n);
        res=res<<n;
        printf("case #%d:\n",i);
        printf("%d\n",res);
    }
    return 0;
}