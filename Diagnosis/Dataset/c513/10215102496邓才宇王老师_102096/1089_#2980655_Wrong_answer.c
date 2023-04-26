#include <stdio.h>
#include <stdlib.h>
#define N 10
void mult_n(int a[],int n)
{
    int i;
    for(i=N-1;i>0;i--)
        a[i]*=n;
    for(i=N-1;i>0;i--)
    {
        a[i-1] += a[i]/10;
        a[i]%=10;
    }
}
void output(int a[],int n)
{
    int i=10-n;
    while(i<10)
        printf("%d",a[i++]);
    printf("\n");
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int a[10];
        a[9]=1;
        int A,B,n;
        scanf("%d %d %d",&A,&B,&n);
        for(int j=0;j<B;j++) mult_n(a,A);
        printf("case #%d:\n",i);
        output(a,n);
    }
}
