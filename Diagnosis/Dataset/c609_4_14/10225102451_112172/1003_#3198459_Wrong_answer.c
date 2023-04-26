#include <stdio.h>
#include <stdlib.h>

void f(long long x,int s[1000])
{
    int i=0;
    for(;x;x/=2333,i++)
        s[i]=x%2333;
    for(i--;i>=0;i--)
    printf("%d ",s[i]);

}
int main()
{
    int n;
    scanf("%d",&n);
    long long x;
    int s[1000];
    for (int i=0;i<n;i++)
    {
        scanf("%d",&x);
        f(x,s);
        printf("\n");

    }
    return 0;
}
