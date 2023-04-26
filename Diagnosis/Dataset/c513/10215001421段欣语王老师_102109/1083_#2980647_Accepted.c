#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,N;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        scanf("%d",&N);
        printf("%d\n",N/5+N/25+N/125+N/625);
    }
    return 0;
}