#include<stdio.h>
#include<stdlib.h>
int main()
{
    char c;
    int n;
    int i,T;
    long long res;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        res=1;
        scanf("%d%d",&a,&n);
        for(j=0;j<n;j++)
        {
            res=res*a;
        }
        printf("case #%d:\n",i);
        printf("%d\n",res);
    }
    return 0;
}