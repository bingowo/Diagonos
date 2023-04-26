#include<stdio.h>
typedef struct NUMBER{
long x;long y;}number;
int f(long x,long y)
{
    int m=0;
    while(x!=0||y!=0)
    {
        if(x%2!=y%2) m+=1;
        x=x/2;y=y/2;
    }
    printf("%d\n",m);
    return 0;

}
int main()
{
    int T;
    scanf("%d",&T);
    struct NUMBER number[T+1];
    for(int i=0;i<T;i++)
    {
        scanf("%ld %ld",&number[i].x,&number[i].y);
    }
    for(int j=0;j<T;j++)
    {
        f(number[j].x,number[j].y);
    }
    return 0;
}