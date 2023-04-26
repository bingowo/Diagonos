#include <stdio.h>
#include <stdlib.h>
int cmpa(const void *a,const void *b)
{
    int *p1=(int *)a;
    int *p2=(int *)b;
    return *p1-*p2;
}
int cmpd(const void *a,const void *b)
{
    int *p1=(int *)a;
    int *p2=(int *)b;
    return *p2-*p1;
}

int main()
{
    char p;
    scanf("%c",&p);
    int a[1000]={0},i=0;
    while(scanf("%d",&a[i])!=EOF) i++;

    if(p=='A'){
        qsort(a,i,sizeof(a[0]),cmpa);
    }
    else {
        qsort(a,i,sizeof(a[0]),cmpd);
    }
    int k = 0;
    for (int o = 1; o < i; o++)
    {
        if (a[k] != a[i])
        {
            a[k + 1] = a[o]; // arr[k + 1] 始终指向“当前已得到的无重复数组”的最后一个元素。
            k++; // k++后，k 对应的既是“当前已得到的无重复数组”的最后一个元素的下标。
        }

    }
    int newLen = k+1;

    int j;
    for( j=0;j<newLen-1;j++){
        printf("%d ",a[j]);

    }
    printf("%d",a[j]);
}
