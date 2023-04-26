#include<stdio.h>

long long T(int n)
{
    if(n==0) return 0;
    else if(n==1||n==2) return 1;
    else return T(n-1)+T(n-2)+T(n-3);
}

int main()
{
    int N; scanf("%d",&N);
    for(int j=0;j<N;j++) {
        int n; scanf("%d",&n);
        printf("case #%d:\n%lld\n",j,T(n));
    }
    return 0;
}