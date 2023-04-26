#include <stdio.h>
int f(int x)
{
    int a,b;
    b=0;
    while(x>0){
        a=x%10;
        b=b*10+a;
        x=x/10;
    }
    return b;
}
int main()
{
    int n,s;
    scanf("%d",&n);
    s=0;
    while(f(n)!=n){
        s++;
        n=n+f(n);
    }
    printf("%d %d\n",s,n);
    return 0;
}