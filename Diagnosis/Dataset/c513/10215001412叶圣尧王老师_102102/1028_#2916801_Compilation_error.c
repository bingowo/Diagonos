提交 #2916736
#	送交者	题目	语言	提交时间	评测时间	结果	耗时	内存	评测机
2916736	10215001412	1028. 排序去重	C	2022-03-10 22:41:09	2022-03-10 22:41:12	
Accepted: 100
0.006	0.613	Seattle
 C
 Copy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmpa(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
int cmpd(const void*a,const void*b)
{
    return *(int*)b-*(int*)a;
}

int main()
{
    char c;scanf("%c",&c);int i,k=0,a[100];
    while(scanf("%d",&a[k])!=EOF)k++;
    if(c=='A')qsort(a,k,sizeof(a[0]),cmpa);
    else qsort(a,k,sizeof(a[0]),cmpd);
    printf("%d",a[0]);
    for(i=1;i<k;i++)if(a[i]!=a[i-1])printf(" %d",a[i]);
}