#include <stdio.h>
#include <stdlib.h>

long long tri(int n);

int main()
{
    int T;
    scanf("%d",&T);
    int cnt = 0;
    long long sum;
    while(T-->0){
        int n;
        scanf("%d",&n);
        if(n == 0) sum = 0;
        if(n == 1 ||n == 2) sum = 1;
        if(n > 2){
            sum = tri(n);
        }
        printf("case #%d:\n",cnt);
        printf("%lld\n",sum);
        cnt++;
    }

}


long long tri(int n){
    long long num[75];
    num[0] = 0;
    num[1] = 1;
    num[2] = 1;
    for(int i = 3;i <75;i++){
        num[i] = num[i-1] + num[i-2] + num[i-3];
    }
    return num[n];
}
