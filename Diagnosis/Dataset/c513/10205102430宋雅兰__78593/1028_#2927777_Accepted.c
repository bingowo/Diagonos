#include<stdio.h>
#include<stdlib.h>
int cmpA(const void*p1,const void*p2)
{
    int a=*((int*)p1);
    int b=*((int*)p2);
    return a-b;
}
int cmpD(const void*p1,const void*p2)
{
    int a=*((int*)p1);
    int b=*((int*)p2);
    return b-a;
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
    if(cmd=='A')
        qsort(a,i,sizeof(a[0]),cmpA);
    else qsort(a,i,sizeof(a[0]),cmpD);
    int j;
    for(j=0;j<i-1;j++)printf("%d ",a[j]);
    printf("%d",a[j]);
    return 0;
}