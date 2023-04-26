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
    int t,j=0;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        int a[10000]={0};
        int b[10000]={0};
        for(int j = 0;j<n;j++){
            scanf("%d",&a[j]);
            //getchar();
        }
        for(int p = 0;p<n;p++){
            scanf("%d",&b[p]);
        qsort(a,j,sizeof(a[0]),cmp);
        qsort(b,j,sizeof(b[0]),cmp);
        int out=0;
        for(int k=0;k<j;k++){
            out+=a[k]*b[n-k-1];
        }
        printf("case #%d:\n",i);
        printf("%d\n",out);
    }
}
