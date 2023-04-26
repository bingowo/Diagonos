#include <stdio.h>
#include <stdlib.h>

int cmpA(const void*a, const void*b)
{
    int*p1=(int*)a;
    int*p2=(int*)b;
    if(*p1<*p2)
    {
        return -1;
    }
    else
        return 1;

}

int cmpD(const void*a, const void*b)
{
    int*p1=(int*)a;
    int*p2=(int*)b;
    if(*p1<*p2)
    {
        return 1;
    }
    else
        return -1;
}

int main()
{
    int A[100];
    int B[100];
    int* p=A;
    int i=0,k=0;
    char s;
    s=getchar();
    while(scanf("%d",&A[i])!=EOF)
    {
        i++;
    }
    if(s=='A')
    {
        qsort(p,i,sizeof(A[0]),cmpA);
    }
    else
    {
        qsort(p,i,sizeof(A[0]),cmpD);
    }
    for(int j=0;j<i;j++)
    {
        while(A[j]==A[j+1])
        {

            j++;
        }
        B[k]=A[j];
        k++;
    }
    for(int j=0;j<k;j++)
    {
        if(j==k-1)
            printf("%d",B[j]);
        else
        printf("%d ",B[j]);
    }

}
