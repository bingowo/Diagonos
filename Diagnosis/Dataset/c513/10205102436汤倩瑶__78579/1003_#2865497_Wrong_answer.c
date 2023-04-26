#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void*a,const void*b)
{
    
    
    
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int n;
        scanf("%d",&n);
        int *a=(int *)malloc(sizeof(int)*n);
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
            printf("%d",a[j]);


        }



    }

}
