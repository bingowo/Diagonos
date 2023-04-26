#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int a[509];
int b[509];
int n,m;

int cmp(const void* x,const void* y)
{
    int flag1=501+*(int*)x,flag2=501+*(int*)y;
    for(int i=0;i<n;i++){
        if(*(int*)x==a[i])flag1=i;
        if(*(int*)y==a[i])flag2=i;
    }
    return flag1-flag2;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    qsort(b,m,sizeof(int),cmp);
    for(int i=0;i<m;i++)printf("%d ",b[i]);
    return 0;
}