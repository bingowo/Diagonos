#include<stdio.h>
#include<stdlib.h>
int table[2000];
int cmp(void* a,void *b)
{
    int a1=*(int *)a,b1=*(int *)b;
    return table[a1]-table[b1];
}
int cmp1(void* a,void *b)
{
    int a1=*(int *)a,b1=*(int *)b;
    return a1-b1;
}
int main()
{
    for(int j=0;j<2000;j++) table[j]=-1;
    int n,tmp;
    scanf("%d",&n);
    for(int j=0;j<n;j++)
    {
        scanf("%d",&tmp);
        table[tmp]=j;
    }
    int b[1000];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    int ex[1000],no[1000],count1=0 ,count2=0;
    for(int i=0;i<n;i++)
    {
        if(table[b[i]]>=0) ex[count1++]=b[i];
        else no[count2++]=b[i];
    }
    qsort(ex,count1,sizeof(ex[0]),cmp);
    for(int i=0;i<count1;i++) printf("%d ",ex[i]);
    qsort(no,count2,sizeof(no[0]),cmp1);
    for(int i=0;i<count2;i++) printf("%d ",no[i]);
}
