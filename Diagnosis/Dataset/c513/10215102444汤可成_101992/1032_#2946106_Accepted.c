#include <stdio.h>
#include <stdlib.h>

int cmp(const void*pa, const void*pb)
{
    int*a = (int*)pa;
    int*b = (int*)pb;
    int j = 0;
    while(j<51)
    {
        if(a[j] > b[j]) return -1;
        else if(a[j] < b[j]) return 1;
        else
        {
            j++;
        }
    }

}

int main()
{
    int T  = 0;
    scanf("%d", &T);
    int i = 0;
    for(i = 0; i<T; i++)
    {
        int n = 0;
        scanf("%d", &n);
        int arr[1001][51] = {0};
        for(int j = 0; j<n; j++)
        {
            int p = 0;
            do
            {
                scanf("%d", &arr[j][p++]);
            }
            while(arr[j][p-1] != -1);
        }
        qsort(arr, n, sizeof(arr[0]), cmp);
        for(int j = 0; j<n; j++)
        {
            int p = 0;
            while(arr[j][p] != -1)
            {
                printf("%d ",arr[j][p++]);
            }
            printf("\n");
        }
    }
    return 0;
}
