#include <stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    int i,j=0;
    long long int a,b;
    int s[20];
    for(i=0;i<T;i++)
    {
        j=0;
        scanf("%lld",&a);
        while(a/2333!=0){
            b=a%2333;
            s[j]=b;
            j++;
            a=a/2333;

        }
        if(a/2333==0){
            s[j]=a;
        }
        for(;j>=0;j=j-1){
            printf("%d ",s[j]);

        }
        printf("\n");


    }

    return 0;
}
