#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
    if((*(int*)a)>(*(int*)b)) return 1;
    else return -1;
}
int cmp1(const void*a,const void*b)
{
    if((*(int*)a)<(*(int*)b)) return 1;
    else return -1;
}
int main()
{
    int a[1001],i = 0,j;
    char c;
    scanf("%c",&c);
    while((scanf("%d",&a[i]))!=EOF) i++;
    if(i==1) printf("%d",a[0]);
    else {for(j = 1;j<i;j++)
    {
        if(c=='A')
        {
            qsort(a,i,sizeof(int),cmp);
            if(j==1) printf("%d ",a[0]);
            if(a[j]!=a[j-1]) printf("%d ",a[j]);
        }
        else
        {
            qsort(a,i,sizeof(int),cmp1);
            if(j ==1) printf("%d ",a[0]);
            if(a[j]!=a[j-1]) printf("%d ",a[j]);
        }

    }}
    return 0;
}
