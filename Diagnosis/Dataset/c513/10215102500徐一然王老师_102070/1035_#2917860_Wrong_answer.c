#include <stdio.h>
#include <stdlib.h>

typedef struct yuan{long long int R;long long int H;long long int Sce;long long int Sdi;long long int Ssum;}A;

//int cmp1(const void*a,const void*b)
//{
//    A* p1=(A*)a;
//    A* p2=(A*)b;
//    if(p1->Ssum<p2->Ssum)
//    {
//        return 1;
//    }
//    else
//        return -1;
//}

int cmp2(const void*a,const void*b)
{
    A* p1=(A*)a;
    A* p2=(A*)b;
    if(p1->Sce<p2->Sce)
    {
        return 1;
    }
    else
        return -1;
}

int main()
{
    int n,m;
    long long int sum=0;
    long long int max=0;
    A C[1001];
    A *p=C;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%lld %lld",&C[i].R,&C[i].H);
    }
    for(int i=0;i<n;i++)
    {
        C[i].Sce=2*C[i].H*C[i].R;
        C[i].Sdi=C[i].R*C[i].R;
        C[i].Ssum=C[i].Sce+C[i].Sdi;
    }
    qsort(p,n,sizeof(C[0]),cmp2);
    for(int i=0;i<n;i++)
    {
        sum=sum+C[i].Ssum;
        for(int j=0;j<m;j++)
        {
            if(j==i)
                continue;
            if(C[j].R>C[i].R)
            {
                continue;
            }
            else
            {
                sum=sum+C[j].Sce;
            }
        }
        if(max<sum)
        {
            max=sum;
        }
        sum=0;

    }
    printf("%lld\n",max);



}
