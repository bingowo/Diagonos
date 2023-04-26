#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
    int* A = *(int(*)[51])a;
    int* B = *(int(*)[51])b;
    int j = 0;
    do
    {
        if(A[j] != B[j])
            return A[j] < B[j];
        j++;
    }while(A[j] != -1 && B[j] != -1);

    if(A[j] == -1)
        return 1;
    else
        return -1;
}

int main()
{
    int T1;
    int T2;
    int a[1000][51];
    scanf("%d",&T1);
    for(int i = 0;i < T1; i++)
    {
        scanf("%d",&T2);
        int j = 0;
        int k = 0;
        do
        {
            scanf("%d",&a[j][k]);
            if(a[j][k] == -1)
            {
                j++; k = 0;
            }
            else
                k++;

        }while(j < T2);
        qsort(a,T2,sizeof(a[0]),cmp);
        j = 0; k = 0;
        do
        {
            printf("%d ",a[j][k]);
            k++;
            if(a[j][k] == -1)
            {
                j++; k =0;
                printf("\n");
            }
        }while(j < T2);

    }
}
