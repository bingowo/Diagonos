#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int n;
void solve(int n)
{
    long long res=0;
    for(int i=n;i>=0;i--){
        for(int j=0;2*j+i<=n;j++){
            for(int m=0;3*m+2*j+i<=n;m++){
                for(int p=0;4*p+3*m+2*j+i<=n;p++){
                    if(4*p+3*m+2*j+i==n)res++;
                }
            }
        }
    }
    printf("%lld\n",res);
}
long long solve4(int i,int j,int m)
{
    long long res4=0;
    for(int p=0;4*p+3*m+2*j+i<=n;p+=4){
        if(4*p+3*m+2*j+i<=n)
            res4++;
    }
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
