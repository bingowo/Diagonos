#include <stdio.h>
#include <string.h>
long long int g(int n,long long int num[50]){
    long long int x=0;
    for(int i=1;i<5&&i<=n;i++){
        if(n>i) x=x+num[n-i-1];
        else x++;
    }
    num[n-1]=x;
    return x;
}
int main()
{
    int t,i;
    long long int num[50];
    scanf("%d",&t);
    num[0]=1;
    for(i=1;i<50;i++){
        num[i]=g(i+1,num);
    }
    int a[t];
    for(i=0;i<t;i++) scanf("%d",&a[i]);
    for(i=0;i<t;i++){
        printf("case #%d:\n%lld\n",i,num[a[i]-1]);
    }
    return 0;
}
