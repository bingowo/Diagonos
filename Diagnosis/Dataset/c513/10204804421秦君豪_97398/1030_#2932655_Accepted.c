#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  lli long long int


int cmp(const void*a,const void *b)
{
    lli*a1=(lli*)a;
    lli*b1=(lli*)b;
    lli tmp1=*a1;
    lli tmp2=*b1;
    int n1=0,n2=0;
    if((*a1)<0)
    {
        tmp1=-1*(*a1);
    }
    if((*b1)<0)
    {
        tmp2=-1*(*b1);
    }
    while(tmp1/10)
    {
        tmp1/=10;
    }
    while(tmp2/10)
    {
        tmp2/=10;
    }
    if(tmp1!=tmp2) return tmp1>tmp2?-1:1;
    else return  (*a1)>(*b1)?1:-1;



}
int main(void)
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        lli *num=(lli*)malloc(N*sizeof(lli));
        memset(num,0,N);
        for(int j=0;j<N;j++)
        {
            scanf("%lld",num+j);
        }
//        for(int k=0;k<N;k++){
//            printf("%lld%c",*(num+k),(k==N-1)?'\n':' ');
//        }
        qsort(num,N,sizeof(lli),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<N;k++){
            printf("%lld%c",*(num+k),(k==N-1)?'\n':' ');
        }
        free(num);
    }
    system("pause");
    return 0;
}
