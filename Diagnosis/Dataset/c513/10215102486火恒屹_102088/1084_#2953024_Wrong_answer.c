#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    int res[31]={0};
    res[0]=1;
    res[1]=2;
    for(int i=2;i<31;i++)
        res[i]=res[i-1]*2;
    for(int i=0;i<T;i++)
    {
        printf("case #%d\n:",i);
        int num;
        scanf("%d",&num);
        printf("%d\n",res[num]);
    }
    return 0;
}
