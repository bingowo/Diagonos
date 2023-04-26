#include <stdio.h>
#include <stdlib.h>

long long int jump(int n);

int main()
{
    int T;
    scanf("%d",&T);
    int cnt = 0;
    while(T-- > 0){
        int n;
        scanf("%d",&n);
        long long int sum = jump(n);
        printf("case #%d:\n",cnt);
        printf("%lld\n",sum);
        cnt++;
    }
}


long long int jump(int n)
{
    if(n < 3){
            return n;
    }
    if(n == 3) return 4;
    if(n == 4) return 8;
    else{
        return jump(n-2) + jump(n-1) + jump(n-3) + jump(n-4);
    }
}
