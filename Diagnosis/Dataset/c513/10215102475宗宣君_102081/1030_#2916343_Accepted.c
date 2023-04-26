#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int num(long long int a)
{
    long long int n;
    if(a<0) a = -1*a;
    while(a/10!=0) a/=10;
    n = a%10;
    return n;
}
int cmp(const void*a,const void*b)
{
    long long A,B;
    A = *(long long *)a;B= *(long long *)b;
    if(num(A)<num(B)) return 1;
    else if(num(A)== num(B)&&A>B) return 1;
    else return -1;

}
int main()
{
    int T,i,j;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        long long int a[N];
        for(j = 0;j<N;j++)
        {
            scanf("%lld",&a[j]);
        }
        printf("case #%d:\n",i);
        if(N==1) printf("%d\n",a[0]);
        else {qsort(a,N,sizeof(long long),cmp);
        for(j = 0;j<N;j++)
            printf("%lld ",a[j]);
            printf("\n");}

    }
    return 0;
}
