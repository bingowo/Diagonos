#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int cmp1(const void *a,const void *b)
{
    int *p1=(int*)a;
    int *p2=(int*)b;
    if(*p1<*p2)
    {
        return -1;
    }
    else return 1;

}


int cmp2(const void *a,const void *b)
{
    int *p1=(int*)a;
    int *p2=(int*)b;
    if(*p1>*p2)
    {
        return -1;
    }
    else return 1;

}

int main()
{
    int count,count1;
    scanf("%d",&count);
    count1=count;
    while(count--)
    {
        int weidu;
        int A[100];
        int*p1=A;
        int B[100];
        int*p2=B;
        scanf("%d",&weidu);
        for(int i=0;i<2;i++)
        {
            if(i==0)
            {
                for(int j=0;j<weidu;j++)
                {
                scanf("%d",&A[j]);
                }
            }
            else if(i==1)
            {
                for(int j=0;j<weidu;j++)
                {
                scanf("%d",&B[j]);
                }
            }

        }
        qsort(p1,weidu,sizeof(A[0]),cmp1);
        qsort(p2,weidu,sizeof(B[0]),cmp2);
        printf("case #%d:\n",count1-count-1);
        int sum=0;
        for(int k=0;k<weidu;k++)
        {
            sum=sum+A[k]*B[k];
        }
        printf("%d\n",sum);

    }
}
