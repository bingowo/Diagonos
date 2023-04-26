#include <stdio.h>
#include <math.h>
int main()
{
    int N,i = 0,m;
    scanf("%d",&N);
    for(i = 0;i<N;i++)
    {
        scanf("%d",&m);
        printf("case #%d:\n",i);
        printf("%d\n",(int)pow(2,m));
    }
    return 0;
}
