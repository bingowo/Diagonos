#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
long long sol[51];
long long solve(int n)
{
    if(sol[n]!=0)return sol[n];
    else{
        sol[n]=solve(n-1)+solve(n-2)+solve(n-3)+solve(n-4);
        return sol[n];
    }
}
int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<51;i++)sol[i]=0;
    sol[1]=1;sol[2]=2;sol[3]=4;sol[4]=8;
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        int n;
        scanf("%d",&n);
        printf("%lld\n",solve(n));
    }
}
