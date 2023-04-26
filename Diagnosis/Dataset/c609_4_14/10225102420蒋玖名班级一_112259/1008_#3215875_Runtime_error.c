#include <stdio.h>
#include <stdlib.h>
typedef struct Num{
long long n;
int cnt;
}Num;
int f(long long n)
{
    int count=0,sign=0,a;
    if(n<0){
        n=-n-1;
        sign=1;
    }
    do{
        a=n%2;
        n/=2;
        if(a==1) count++;
    }while(n!=0);
    if(sign) return 64-count;
    return count;
}
int cmp(Num A,Num B)
{
    if(A.cnt>B.cnt)
        return -1;
    else if(A.cnt<B.cnt)
        return 1;
    else
    {
        if(A.n<B.n) return -1;
        else return 1;
    }
}
int main()
{
    int T;scanf("%d",&T);
    long long mi;
    for(int i=0;i<T;i++)
    {

        int N;scanf("%d",&N);
        Num nums[N];
        for(int j=0;j<N;j++)
            {scanf("%lld",&nums[j].n);
            long long tmp=nums[j].n;
            nums[j].cnt=f(nums[j].n);}
        qsort(nums,N,sizeof(nums[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<N;j++)
            printf("%lld ",nums[j].n);
        printf("\n");
    }
    
    return 0;
}
