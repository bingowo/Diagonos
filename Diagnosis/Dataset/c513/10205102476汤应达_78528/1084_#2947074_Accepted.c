#include<stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    int in[T],res;
    for(int i=0;i<T;i++) scanf("%d",&in[i]);
    for(int i=0;i<T;i++)
    {
        res=1;
        for(int t=0;t<in[i];t++) res*=2;
        printf("case #%d:\n%d\n",i,res);
    }
}
