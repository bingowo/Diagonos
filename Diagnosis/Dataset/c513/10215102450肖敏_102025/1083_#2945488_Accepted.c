#include <stdio.h>
int fun(int n)
{
    int num =0;
    int i,j;
    for(i=5;i<=n;i+=5)
    {
        j=i;
        while(j%5==0)
        {
            num ++;
            j/=5;
        }
    }
    return num;
}
int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        int sum;
        sum=fun(n);
        printf("case #%d:\n%d\n",i,sum);
    }
    return 0;
}
