#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    long long a,b[100],c;
    int m,n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        m=0;
        scanf("%lld",&a);
        if(a == 0)
        {
            printf("0\n");
            continue;
        }
        while(a)
        {
            b[m]=a%2333;
            m++;
            a/=2333;
        }
        m--;
        while(m)
        {
            printf("%lld ",b[m]);
            m--;
        }
        printf("%d\n",b[0]);/*while中没有遍历到0*/
    }
    return 0;
}
