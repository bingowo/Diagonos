#include <stdio.h>
#include <stdlib.h>

int Dic[10];

int cmp1(int *a,int*b)
{
    if(Dic[*a]<Dic[*b])
    {
        return -1;
    }
    else return 1;
}

int cmp(int *a,int *b)
{
    return *a-*b;
}

int main()
{
    int m,n,k=0,flag=0,p=0;
    int temp;
    int A[501];
    int B[501];
    int C[501];
    int D[501];
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&A[i]);
        temp=A[i];
        Dic[temp]=i;
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&B[i]);
    }
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<m;j++)
        {
            if(B[i]==A[j])
            {
                C[k]=B[i];
                k++;
                flag=1;
                break;
            }
        }
            if(flag==0)
            {
                D[p]=B[i];
                p++;
            }
            flag=0;

    }
    qsort(C,k,sizeof(C[0]),cmp1);
    qsort(D,p,sizeof(D[0]),cmp);
    for(int i=0;i<k;i++)
    {
        printf("%d ",C[i]);
    }
    for(int i=0;i<p-1;i++)
    {
        printf("%d ",D[i]);
    }
    printf("%d",D[p-1]);

}
