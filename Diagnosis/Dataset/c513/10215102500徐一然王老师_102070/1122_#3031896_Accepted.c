#include <stdio.h>

int main()
{
    int cnt;
    scanf("%d",&cnt);
    while(cnt--)
    {
        long long int a;
        int A[1000]={0};int i=0;
        scanf("%lld",&a);
        while(a)
        {
            A[i]=a%2333;
            a=a/2333;
            i++;
        }
        i--;
        for(i;i>0;i--)
        {
            printf("%d ",A[i]);
        }
        printf("%d\n",A[0]);

    }
}
