#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T = 0;
    scanf("%d",&T);
    for(int i =0;i<T;i++){
        int N = 0;
        scanf("%d",&N);
        int res = 1<<N;
        printf("case #%d:\n%d\n",i,res);
    }
    return 0;
}
