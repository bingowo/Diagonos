#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    char a[1001];
    scanf("%s",a);
    long long sum=1;
    int n=strlen(a);
    if(n==1){printf("1");return 0;}
    if(a[0]==a[1]){sum*=1;}
    else sum*=2;
    if(a[n-1]!=a[n-2]){sum*=2;}
    else sum*=1;
    for(int i=1;i<n-1;i++)
    {
        if(a[i]!=a[i-1]&&a[i]!=a[i+1]&&a[i-1]!=a[i+1]) sum*=3;
        else{if(a[i]==a[i-1]&&a[i]==a[i+1]) sum*=1;
             else sum*=2;}
             sum=sum%1000000007;
    }
    printf("%lld",sum);
}
