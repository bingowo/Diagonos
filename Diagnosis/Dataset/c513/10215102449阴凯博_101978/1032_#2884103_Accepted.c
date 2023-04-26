#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int arr[51];
} LINE;


int cmp(const void* a,const void* b)
{
    LINE* pa=(LINE*)a; LINE* pb=(LINE*)b;
    int i=0;
    while (!(pa->arr[i]==-1 || pb->arr[i]==-1))
    {
        if (pa->arr[i]>pb->arr[i]) return -1;
        if (pa->arr[i]<pb->arr[i]) return 1;
        if (pa->arr[i]==pb->arr[i]) i++;
    }
    if (pa->arr[i]==-1) return 1;
    if (pb->arr[i]==-1) return -1;
}

int main()
{
    int T,N,j,m=0,k=0;
    scanf("%d",&T);
    char s[120]={0};
    for (int i=0;i<T;i++)
    {
        scanf("%d",&N);
        LINE* arr1=(LINE*)malloc(N*sizeof(LINE));
        for (j=0;j<N;j++)
        {
            while (m!=-1)
            {
                scanf("%d",&m);
                arr1[j].arr[k++]=m;
            }
            m=0; k=0;
        }
        qsort(arr1,N,sizeof(LINE),cmp);
        for (j=0;j<N;j++)
        {
            k=0;
            while(1)
            {
                printf("%d",arr1[j].arr[k++]);
                if (arr1[j].arr[k]==-1)
                {
                    printf("\n");
                    break;
                }
                else printf(" ");
            }

        }
        k=0;
        free(arr1);

    }
    return 0;
}
