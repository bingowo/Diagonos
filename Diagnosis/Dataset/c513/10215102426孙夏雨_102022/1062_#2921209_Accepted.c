#include <stdio.h>
#include <stdlib.h>

long long int f(int x)
{
    long long int x1=1,x2=2,x3=4,x4=8,all=0;
    if(x==1) return 1;
    else if(x==2) return 2;
    else if(x==3) return 4;
    else if(x==4) return 8;
    else {
        for(int i=5;i<=x;i++){
            all=x1+x2+x3+x4;
            x1=x2;
            x2=x3;
            x3=x4;
            x4=all;
        }
        return all;
    }
}

int main()
{
    int T=0;
    scanf("%d",&T);
    long long int all=0;
    int jieshu=0;
    for(int t=0;t<T;t++){
        scanf("%d",&jieshu);
        all=f(jieshu);
        printf("case #%d:\n",t);
        printf("%lld\n",all);
    }
    return 0;
}
