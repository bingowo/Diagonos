#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int cmp(const void *_a,const void *_b)
{
    int* a=(int*)_a;
    int* b=(int*)_b;
    if (fabs(*a/10)>fabs(*b/10)) return -1;
    else if(fabs(*a/10)<fabs(*b/10)) return 1;
    else return *a>*b;
}
int main()
{
    int i=0,a[1000],j;
    while(scanf("%d",&a[i])!=EOF){
            i++;
    }
    qsort(a,i,sizeof(a[0]),cmp);
    for(j=0;j<i;j++){
        printf("%d ",a[j]);
    }
    return 0;
}
