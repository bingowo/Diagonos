#include<stdio.h>
#include<stdlib.h>
typedef long long int lli;
int num1(lli n)
{
    int d=1,a=0;
    for(int t=0;t<64;t++)
    {
        if(d&n)a=a+1;
        d=d<<1;
    }
    return a;
}
int cmp(const void*a,const void* b)
{
    lli d1=*((lli*)a),d2=*((lli*)b);
    int a1=num1(d1),a2=num1(d2);
   if(a1!=a2)return a2-a1;
   else return d1<d2?-1:1;
}
int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for(int i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        getchar();
        lli p[N];
        for(int j=0;j<N;j++)
        {
            scanf("%lld",&p[j]);
        }
        qsort(p,N,sizeof(lli),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<N;k++)
        {

            printf("%lld%c",p[k],(k!=(N-1))?' ':'\n');
        }

    }
    return 0;


}
