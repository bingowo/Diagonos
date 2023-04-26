#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int n;
void solve(int n)
{
    long long res=0;
    for(int j=0;2*j<=n;j++){
        for(int m=0;3*m<=n;m++){
            for(int p=0;4*p<=n;p++){
                if(4*p+3*m+2*j<=n)res++;
            }
        }
    }
    printf("%lld\n",res);
}
int main()
{
    int T;scanf("%d",&T);
    for(int step=0;step<T;step++){
        scanf("%d",&n);
        if(n==0)printf("0\n");
        else if(n==1)printf("1\n");
        else solve(n);
    }
    return 0;
}
