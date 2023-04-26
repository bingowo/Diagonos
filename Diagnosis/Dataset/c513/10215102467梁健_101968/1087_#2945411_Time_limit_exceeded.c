#include<stdio.h>
#include<string.h>

int main()
{
    int T;scanf("%d",&T);long long A;
    int judge(long long a)
    {
        char jud[101];
        long long c=a;int m=0;
        do{
            jud[m++]=c%10;
            c/=10;
        }while(c>0);
        if(m==1)return 1;
        int step=1;
        for(;step<m;step++){
            if(jud[step]==jud[step-1])break;
        }
        if(step==m-1)return 1;
        else return 0;
    }
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        scanf("%lld",&A);
        A++;
        for(;judge(A)!=1;A++);
        printf("%lld\n",A);
    }
    return 0;
}
