#include <stdio.h>

int main()
{
    int T, N;
    scanf("%d",&T);
    for(int i=0; i<T; ++i){
        scanf("%d",&N);
        printf("case #%d:\n%d\n",i,1<<N);
    }
    return 0;
}
