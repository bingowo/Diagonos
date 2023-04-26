#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        int N;scanf("%d",&N);
        unsigned long long res=1;
        for(int step=0;step<N;step++){
            res*=2;
        }
        printf("%llu",res);
    }
    return 0;
}
