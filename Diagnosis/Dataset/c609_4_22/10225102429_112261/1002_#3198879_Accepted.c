#include <stdio.h>
int f(int n) {
    int a,b,cnt = 1,max = 1;
    while(n)
    {
        a = n%2;
        b = n/2%2;
        n/=2;
        if(a!=b && n!=0) cnt++;
        else if(a==b && n!=0) {max = max>cnt?max:cnt;cnt = 1;}
    }
    return max>cnt?max:cnt;
}
int main()
{
    int T; scanf("%d",&T);
    for(int i = 0; i<T; i++)
    {
        int n; scanf("%d",&n);
        printf("case #%d:\n%d\n",i, f(n));
    }
    return 0;
}