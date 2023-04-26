#include<stdio.h>
#define N 100
int main()
{
    int T,j=0;
    scanf("%d",&T);
    int s[N];
    long long int a;
    for(int i=0;i<T;i++)
    {
        scanf("%lld",&a);
        for(j=0;a!=0;j++)
        {
            s[j]=a%2333;
            a/=2333;
        }
        j--;
        for(;j>=0;j--)
        printf("%d ",s[j]);
        printf("\n");
    }
}