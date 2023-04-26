#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    int R=2333,k=0;
    int a[33];
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        do{
            int r=n%R;
            a[k++]=r;
            n=n/R;
        }while(n);
    for(j=k-1;j>=;j--) printf("%d ",a[j]);
    printf("\n");
    k=0;
    }
    return 0;
}
