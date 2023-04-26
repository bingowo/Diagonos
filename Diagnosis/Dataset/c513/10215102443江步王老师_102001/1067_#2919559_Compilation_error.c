#include<stdio.h>


long long int T(int n);
int main()
{
    int t;
    int n;
    int i;
    scanf("%d",&t);
    for (i=0;i<t;i++){
        scanf("%d",&n);
        printf("case #%d:\n",i);
        printf("%lld\n",T(n));
    }
    return 0;
}

long long int T(int n)
{
    
    long long *a = (long long *)malloc(sizeof(long long)*n);
    int i;
    a[0]=0;
    a[1]=1;
    a[2]=1;
    if (n<=2>){
        return a[n];
    }
    else{
        for (i=3;i<=n;i++){
            a[i]=a[i-1]+a[i-2]+a[i-3];
        }
    }
    return a[n];
}