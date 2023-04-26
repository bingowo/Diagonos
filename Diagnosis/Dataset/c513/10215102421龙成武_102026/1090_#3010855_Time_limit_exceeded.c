#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
    int n;
    double ans;

    do
    {
        scanf("%d", &n);
        ans=pow(10,n*log10(n));
        while(ans>10)
        {
            ans/=10;
        }
        printf("%d",(int)ans);
    }while(n!=0);

    return 0;
}

