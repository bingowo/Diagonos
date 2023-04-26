#include<stdio.h>
#include<stdlib.h>
void swap(int* x,int* y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int cmp(void* x, void* y)
{
    int* a=(int*)x;
    int* b=(int*)y;
    if(*b>*a)
        return 1;
    else 
        return -1;
}
int main()
{
    int n,m;
    int A[500]={0};
    int B[500]={0};
    int i=0,j=0,p=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d",&B[i]);
    }
    qsort(&B[0],m,sizeof(int),cmp);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(B[j]==A[i])
            {
                swap(&B[p],&B[j])
                p++;
            }
        }
    }
    for(i=0;i<m-1;i++)
    {
        printf("%d ",B[i]);
    }
    printf("%d\n",B[m-1]);
    
    return 0;
}