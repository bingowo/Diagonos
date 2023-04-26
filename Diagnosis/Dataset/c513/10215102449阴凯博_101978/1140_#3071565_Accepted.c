#include <stdio.h>
#include <stdlib.h>


int cmp(const void* a,const void* b)
{
    int* pa=(int*) a; int* pb=(int*)b;
    return (*pa-*pb);
}

int main()
{
    int n;
    scanf("%d",&n);
    int* arr=(int*)malloc(n*sizeof(int));
    int* lrr=(int*)malloc(n*sizeof(int));
    scanf("%d",&arr[0]);
    int* arr0=(int*)malloc(arr[0]*sizeof(int));
    for (int j=0;j<arr[0];j++)
        scanf("%d",&arr0[j]);

    scanf("%d",&arr[1]);
    int* arr1=(int*)malloc(arr[1]*sizeof(int));
    for (int j=0;j<arr[1];j++)
        scanf("%d",&arr1[j]);

    int s[120]={0};
    lrr[1]=0;
    qsort(arr0,arr[0],sizeof(int),cmp);
    qsort(arr1,arr[1],sizeof(int),cmp);
    for (int j=0;j<arr[0];j++)
    {
        for (int k=0;k<arr[1];k++)
        {
            if (arr0[j]<arr1[k])
                break;
            if (arr0[j]==arr1[k])
                s[lrr[1]++]=arr0[j];
        }
    }
    int i=2;
    for (i;i<n;i++)
    {
        scanf("%d",&arr[i]);
        lrr[i]=0;
        int* arr3=(int*)malloc(arr[i]*sizeof(int));
        for (int j=0;j<arr[i];j++)
            scanf("%d",&arr3[j]);
        qsort(arr3,arr[i],sizeof(int),cmp);
        for (int j=0;j<lrr[i-1];j++)
        {
            for (int k=0;k<arr[i];k++)
            {
                if (s[j]<arr3[k])
                    break;
                if (s[j]==arr3[k])
                {
                    s[lrr[i]++]=s[j];
                }
            }
        }
        free(arr3);
    }
    for (int j=0;j<lrr[n-1];j++)
        printf("%d%c",s[j],(j==lrr[n-1]-1)?'\n':' ');
    free(arr);
    free(lrr);
    free(arr1);
    free(arr0);
    return 0;
}
