#include<stdio.h>
int main()
{
    int T;int w=2333;
    scanf("%d", &T);
    for (int i=0;i<T;i++)
    {
        unsigned long long A;int b[10];int j=0;
        scanf("%llu",&A);
        do{ int a=A%w;
            b[j++]=a;
            A=A/w;
        }while(A);
        for(j=j-1;j>=0;j--)printf("%d ",b[j]);
        printf("\n");
    }
    return 0;
}