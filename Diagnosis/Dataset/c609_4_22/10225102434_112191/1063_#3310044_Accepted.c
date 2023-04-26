#include <stdio.h>
#include <stdio.h>
#include<string.h>
#define N 50

long long int f(int n)
{
    static long long int m[N];
    if(n==2||n==1){m[n] = n;return n;}
    if(n==3){m[n] = 4;return 4;}
    if(n==4){m[n] = 8;return 8;}
    if(!m[n])m[n] =f(n-1)+f(n-2)+f(n-3)+f(n-4);
    return m[n];
}
int main()
{
    int T;
    scanf("%d",&T);
    int i ;
    int x;
    for(i = 0;i<T;i++){
        scanf("%d",&x);
        printf("case #%d:\n%ld\n",i,f(x));
    }
    return 0;
}

