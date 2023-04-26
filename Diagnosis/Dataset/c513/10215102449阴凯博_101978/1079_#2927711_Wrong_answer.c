#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
    int *pa=(int*)a; int *pb=(int*)b;
    return (*pa>*pb)?1:-1;
}

int main()
{
    int T,j,k,l,h;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int n,m; int a,b;
        scanf("%d %d",&n,&m);
        int* arr=(int*)malloc(n*sizeof(int));
        int* arr1=(int*)calloc((n*(n+1))/2,sizeof(int));
        for (j=0;j<n;j++)
            scanf("%d",&arr[j]);
        for (j=0;j<n;j++)
            arr1[j]=arr[j];
        for (l=2;l<=n;l++)
        {
            for (j,k=0;k+l<=n;k++,j++)
            {
                for (h=0;h<l;h++)
                arr1[j]+=arr[k+h];
            }
        }
        int cnt=j; int result=0;
        qsort(arr1,cnt,sizeof(int),cmp);
        for (j=0;j<m;j++)
        {
            scanf("%d %d",&a,&b);
            result=0;
            for (k=a-1;k<b;k++)
                result+=arr1[k];
            printf("%d\n",result);
        }


        free(arr); free(arr1);

    }
    return 0;
}
