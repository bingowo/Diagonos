#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    int N;
    for(int m=0;m<T;m++){
        scanf("%d",&N);
        printf("case #%d:\n",m);
        printf("%d\n",N/5+N/25+N/125+N/625);
    }
    return 0;
}
