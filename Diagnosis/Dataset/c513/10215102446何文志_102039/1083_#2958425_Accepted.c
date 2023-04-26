#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T = 0;
    scanf("%d",&T);
    for(int i = 0;i<T;i++){
        int N = 0;
        scanf("%d",&N);
        int num5 = N/5,num25 = N/25,num125 = N/125,num625 = N/625;
        int res = num5+num25+num125+num625;
        printf("case #%d:\n",i);
        printf("%d\n",res);
    }
    return 0;
}
