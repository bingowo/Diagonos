#include<stdio.h>
#include<string.h>
int main()
{
    int T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        char s[61];
        scanf("%s",s);
        int a[128];
        for(int step=0;step<128;step++){
            a[step]=-1;
        }
        int num=0,N=1;
        char *p=s;
        a[*p]=1;
        while(*++p){
            if(a[*p]==-1){
                a[*p]=digit;
                if(digit==0)digit=2;
                else digit+=1;
                N++;
            }
        }
        if(N<2)N=2;
        long long res=0;
        p=s;
        while(*p){
            res=res*N+a[*p++];
        }
        printf("%lld\n",ans);
    }
    return 0;
}