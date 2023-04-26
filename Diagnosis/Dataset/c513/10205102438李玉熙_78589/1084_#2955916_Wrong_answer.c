#include<stdio.h>
int f(int n){
    long long sum=1;
    for(int i=0;i<n;i++){
        sum=sum*2;
    }
}
int main()
{
    int T,n,j=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        printf("case #%d:\n%lld\n",j,f(n));
        j++;
    }
}