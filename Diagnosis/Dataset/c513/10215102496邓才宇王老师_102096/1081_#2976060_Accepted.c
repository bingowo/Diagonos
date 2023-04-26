#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
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
void output(int a[])
{
    int i=0;
    while(i<N&& a[i]==0) i++;
    if(i>=N)
    { printf("0\n"); return;}

    while(i<N)
        printf("%d",a[i++]);
    printf("\n");

}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int a,n;
        scanf("%d %d",&a,&n);
        int ans[100]={0};
        ans[99]=1;
        for(int j=0;j<n;j++)
        {
            mult_n(ans,a);
        }
        printf("case #%d:\n",i);
        output(ans);
    }
}
