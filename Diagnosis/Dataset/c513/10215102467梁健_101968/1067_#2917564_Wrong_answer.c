#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
long long sol[75];
long long solve(int n)
{
    if(n==0)return 0;
    if(n==1)return 1;
    if(n==2)return 1;
    if(n==3)return 2;
    if(sol[n]!=0)return sol[n];
    else{
        sol[n]=solve(n-3)+solve(n-2)+solve(n-1);
        return sol[n];
    }
}
int main()
{
    int T;scanf("%d",&T);
    sol[0]=0;sol[1]=1;sol[2]=1;sol[3]=2;
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        int m;
        scanf("%d",&m);
        printf("%d\n",solve(m));
    }
    return 0;
}
