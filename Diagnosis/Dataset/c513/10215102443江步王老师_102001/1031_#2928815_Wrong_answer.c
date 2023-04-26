#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int Acmp(const void *_a, const void *_b);
int Dcmp(const void *_a, const void *_b);
int main()
{
    int T,N;
    int i,j;
    int *p=NULL;
    for (i=0;i<T;i++)
    {
        long long res=0;
        scanf("%d",&N);
        int *a = (int *)malloc(sizeof(int)*N);
        int *b = (int *)malloc(sizeof(int)*N);
        
        p=a;
        for (j=0;j<N;j++)
        {
            
            scanf("%d",p);
            p++;
        }
        p=b;
        for (j=0;j<N;j++)
        {
            
            scanf("%d",p);
            p++;
        }
        
        qsort(a,N,sizeof(int),Acmp);
        qsort(b,N,sizeof(int),Dcmp);
        
        printf("case #%d:\n",i);
        
        for (j=0;j<N;j++){
            res=res+a[j]*b[j];
        }
        printf("%lld\n",res);

    }
    return 0;
}

int Acmp(const void *_a, const void *_b)
{
    int *a=(int *)_a;
    int *b=(int *)_b;
    return (*a-*b);
}

int Dcmp(const void *_a, const void *_b)
{
    int *a=(int *)_a;
    int *b=(int *)_b;
    return (*b-*a);
}