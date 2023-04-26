#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
int cmp(const void*a,const void*b)
{
    int *pa=(int*)a,*pb=(int*)b;
    return *pa>*pb?1:-1;
}
int main() {
    int n,*p,*p0,i,ans=0;
    scanf("%d",&n);
    p=(int*)malloc(n*sizeof(int));p0=p;
    for(i=0;i<n;i++)scanf("%d",p++);
    qsort(p0,n,sizeof(int),cmp);
    for(i=0;i<n;i+=2)ans+=*(p0+i+1)-*(p0+i);
    printf("%d",ans);
    return 0;
}
