#include<stdio.h>
#include<stdlib.h>
int cmp(const void*p1,const void*p2)
{
    int a=*((int*)p1);
    int b=*((int*)p2);
    return a-b;
}
int main()
{
    char cmd;
    scanf("%c",&cmd);
    int n,i=0;
    int a[100];
    char flag[1000]={0};
    while(scanf("%d",&n)!=EOF){
        if(flag[n]==0){
            a[i++]=n;
            flag[n]=1;
        }
    }
    qsort(a,i,sizeof(a[0]),cmp);
    int j;
    for(j=0;j<i-1;j++)printf("%d ",a[j]);
    printf("%d",a[j]);
    return 0;
}