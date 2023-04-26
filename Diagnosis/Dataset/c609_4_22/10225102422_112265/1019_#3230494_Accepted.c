#include<stdio.h>
#include<stdlib.h>
#define N 10e8
struct num1
{
    int count;
    int number;
};
int cmp(const void * e1,const void *e2)
{
    struct num1 p1=*((struct num1*)e1);
    struct num1 p2=*((struct num1*)e2);
    if(p1.count!=p2.count)
    return p2.count-p1.count;
    else
    {
        return p1.number-p2.number;
    }
}
int Getcount(int num)
{
    int i=0;
    while(num!=0)
    {
        num=num/10;
        i++;
    }
    return i;
}
int main()
{
    struct num1* arr=(struct num1*)malloc(sizeof(struct num1)*N);
    int n;
    scanf("%d",&n);int i=0;char c;
    arr[i].number=n;arr[i].count=Getcount(n);
    i=1;
    while((c=getchar())==' ')
    {
        scanf("%d",&n);
        arr[i].number=n;arr[i].count=Getcount(n);
        i++;
    }
    qsort(arr,i,sizeof(arr[0]),cmp);
    int j=0;
    for(j=0;j<i;j++)
    {printf("%d ",arr[j].number);}
    free(arr);
    return 0;
}