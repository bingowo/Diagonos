#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;//升序
}

int main()
{
    int sum=0,n;
    scanf("%d",&n);//点的数量
    int count=0,num[100002],a[50001],b[50001],i,j;

    //读入数字的同时记录长度
    while (scanf("%d",&num[count])!=EOF)
    count++;
    qsort(num,n,sizeof(num[0]),cmp);//升序排列
    for(j=0;j<n/2;j++){
        a[j]=num[2*j];
        b[j]=num[2*j+1];
    }//分别把单数和双数的数存入ab数组
    for(j=0;j<n/2;j++){
        sum+=abs(a[j]-b[j]);
        printf("%d %d\n",a[j],b[j]);
    }
    printf("%d\n",&sum);
    return 0;
}