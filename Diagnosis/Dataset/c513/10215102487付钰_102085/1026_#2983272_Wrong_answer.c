#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
int cmp(const void *a,const void *b)
{
    int *p1=(int *)a;
    int *p2=(int *)b;
    if(*p1>*p2) return *p1-*p2;
    else return *p2-*p1;
}
int main()
{
    int n,out;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    for(int j=0;j<n;j+=2){
        out += abs(a[j]-a[j+1]);
    }
    printf("%d",out);
}
