#include <stdio.h>
#include <stdlib.h>

int cmp(const void* e1, const void* e2);
int main()
{
    int T,N;
    long long *num;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d",&N);getchar();
        num = (long long*)malloc(N*sizeof(long long));
        for(int j=0;j<N;j++)
        {
            scanf("%lld",num[j]);
        }
        qsort(num,N,sizeof(long long),cmp);
        for(int j=0;j<N;j++)
        {
            printf("%lld",num[j]);
        }
    }
    system("pause");
    return 0;
}

int cmp(const void* e1, const void* e2)
{
    long long mask=1LL,n1 = *(long long*)e1, n2 = *(long long*)e2;
    int m1,m2;
    for(int i=1;i<64;i++)
    {
        m1+=n1&mask;
        mask<<i;
    }
    mask=0LL;
    for(int i=1;i<64;i++)
    {
        m2+=n2&mask;
        mask<<i;
    }
    if(m1!=m2)
        return m1-m2;
    else return n1-n2; 
}