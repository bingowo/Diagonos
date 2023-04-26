#include<stdio.h>
int main()
{
    int T,N,m = 0;
    long long a[11111];
    long long cmp(const void *a,const void *b);
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        m = 0;
        scanf("%d",&N);
        do{
            scanf("%lld",&a[m++]);
        }while(getchar() == ' ');
        qsort(a,m,sizeof(long long),cmp);
        printf("case #%d:\n",i);
        for(int j = 0;j < N;j++){
            printf("%lld%c",a[j],(j == m - 1)?'\n':' ');
        }
    }
    return 0;
}
long long cmp(const void *a,const void *b)
{
    long long *pa = (const long long *) a;
    long long *pb = (const long long *) b;
    long long cnta = 0,cntb = 0;
    long long vala,valb;
    vala = *pa,valb = *pb;
    for(int i = 0;i < 64;i++){
        if((vala>>i)&1) cnta++;
        if((valb>>i)&1) cntb++;
    }
    if (cnta == cntb) return (*pa > *pb)?1:-1;
    else return cntb - cnta;
}
