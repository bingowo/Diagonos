#include <stdio.h>
#include <stdlib.h>
int num[1003][51];
int cmp(const void *a,const void *b){
    int *x = (int*)a;
    int *y = (int*)b;
    int i;
    for(int i=0;(-1!=x[i])&&(-1!=y[i]);i++){
        if(x[i]>y[i]){
            return -1;
        }
        if(x[i]<y[i]){
            return 1;
        }

    }
    if ( (-1 == x[i]) && (-1 == y[i]))
    {
        return 0;
    }
    if ( -1 == y[i])
    {
         return -1;
    }
    return 1;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=0;cas<t;cas++){
        int n,a;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
                a=1;
            for(int j=0;a!=-1;j++){
                scanf("%d",&a);
                num[i][j]=a;
            }
        }
        qsort(num,n,sizeof(num[0]),cmp);
        for(int i=0;i<n;i++){
            for(int j=0;num[i][j]!=-1;j++){
                printf("%d ",num[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
