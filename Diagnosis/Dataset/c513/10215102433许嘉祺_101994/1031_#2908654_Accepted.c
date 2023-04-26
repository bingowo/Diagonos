#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int cmp(const void*a,const void*b){
    int a1=*(int*)a,b1=*(int*)b;
    return a1-b1;
}


int main()
{
    int t;
    scanf("%d",&t);
    int a[1000];
    int b[1000];
    for (int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        for (int j=0;j<n;j++)scanf("%d",&a[j]);
        for (int j=0;j<n;j++)scanf("%d",&b[j]);
        printf("case #%d:\n",i);
        qsort(a,n,sizeof(a[0]),cmp);
        qsort(b,n,sizeof(a[0]),cmp);
        int m=0;
        for (int j=0;j<n;j++) m+=a[j]*b[n-j-1];
        printf("%d\n",m);
    }
    return 0;
}