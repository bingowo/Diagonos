#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    int *p1 = (int *)a;
    int *p2 = (int *)b;
    return *p1-*p2;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        int a[1000]={0};
        int b[1000]={0};//100不够
        for(int j=0;j<n;j++){
            scanf("%d",&a[j]);
        }
        
        for(int x=0;x<n;x++){
            scanf("%d",&b[x]);
        }
        
        qsort(a,n,sizeof(a[0]),cmp);//ab数组是分开给的 不是交替
        qsort(b,n,sizeof(b[0]),cmp);
        int out=0;
        for(int k=0;k<j;k++){
            out+=a[k]*b[n-k-1];
        }
        printf("case #%d:\n",i);
        printf("%d\n",out);
    }
}
