#include <stdio.h>
#include <string.h>
long long int f(int n){
    long long int x=0;

    for(int i=1;i<5&&i<=n;i++){
        //if(i!=1)x += n-i+1;
        if(n>i) x=x+f(n-i);
        else x++;
    }
    return x;
}
int main()
{
    int t,i;
    scanf("%d",&t);
    int a[t];
    for(i=0;i<t;i++) scanf("%d",&a[i]);
    for(i=0;i<t;i++){
        printf("case #%d:\n%lld\n",i,f(a[i]));
    }
    return 0;
}
