#include <stdio.h>
#include <stdlib.h>

int cmp(const void *p1,const void *p2)
{
    int *a=(int*)p1;
    int *b=(int*)p2;
    if(f(*a)==f(*b))
        return *a-*b;
    return f(*b)-f(*a);
}
int f(int n)
{
    if(n<0)
        n=-n;
    int answer=0;
    while(n)
    {n/=10;answer++;}
    return answer;
}
int main()
{
    int* values=(int*)malloc(sizeof(int)*100002);
    int *p=values;
    int i=0;
    while(scanf("%d",p++)!=EOF)
        i++;
    qsort(values,i,sizeof(int),cmp);
    for(int j=0;j<i;j++)
        printf("%d ",*(values+j));
    return 0;


}
