#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    char a[1001];
    scanf("%s",a);
    int sum;
    int n=strlen(a);
    if(n==1){printf("1");return 0;}
    if(a[0]==a[1]){sum*=1;}
    else sum*=2;
    if(a[n]!=a[n-1]){sum*=2;}
    else sum*=1;
    for(int i=1;i<n-1;i++)
    {
        if(a[n]!=a[n-1]&&a[n]!=a[n+1]&&a[n-1]!=a[n+1]) sum*=3;
        else{if(a[n]==a[n-1]&&a[n]==a[n+1]&&a[n-1]==a[n+1]) sum*=1;
             else sum*=2;}
             sum=sum%1000000007;
    }
    printf("%d",sum);
}
