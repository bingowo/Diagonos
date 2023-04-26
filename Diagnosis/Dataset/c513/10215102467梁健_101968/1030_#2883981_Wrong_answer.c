#include<stdio.h>
#include<string.h>
#include<math.h>
int comp(const void *a,const void *b)
{
    long long *a1,*b1;
    a1=(long long *)a,b1=(long long *)b;
    int n1=0,n2=0;
    long long a2=*a1,b2=*b1;
    if(a2<0)a2=-a2;
    if(b2<0)b2=-b2;
    for(;a2/10>9;){
        a2/=10;
    }
    for(;b2/10>9;){
        b2/=10;
    }
    if(0<=a2&&a2<=9){
        n1=a2;
    }
    else n1=a2/10;
    if(0<=b2&&b2<=9){
        n2=b2;
    }
    else n2=b2/10;
    if(n1!=n2)return n2-n1;
    else return (*a1>*b1)?1:-1;

}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d\n:",i);
        int N;
        scanf("%d",&N);
        long long s[N];
        for(int m=0;m<N;m++){
            scanf("%lld",&s[m]);
        }
        qsort(s,N,sizeof(long long),comp);
        int step=0;
        for(;step<N-1;step++){
            printf("%lld ",s[step]);
        }
        printf("%lld\n",s[N-1]);

    }
    return 0;
}
