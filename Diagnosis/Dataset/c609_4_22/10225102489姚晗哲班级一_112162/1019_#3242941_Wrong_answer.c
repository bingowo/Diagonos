#include <stdio.h>
#include <stdlib.h>
int len(int a)
{
    int m=0;
    while((a/10)!=0)
    {
        m++;
        a/=10;
    }
    return m;

}
int compare(const void*a,const void*b)
{
    int *p1=(int*)a;
    int *p2=(int*)b;
    if(len(*p1)==len(*p2))
        return *(int*)a-*(int*)b;
    else
        return len(*p2)-len(*p1);
}
int main()
{
    int m[1000000];
    int i=0;
    do
    {
        scanf("%d",&m[i++]);
    }while(getchar()!='\n');
    qsort(m,i,sizeof(int),compare);
    for(int n=0;n<i;n++)
        scanf("%d ",m[n]);
    return 0;
}