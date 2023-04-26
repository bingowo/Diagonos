#include <stdio.h>
#include <math.h>

int main()
{
    long long int num;scanf("%lld",&num);
    long long int ans[10010] = {0};
    int cnt = 0;
    long long int a = num/-2;
    long long int b = num%-2;
    if(b < 0) {
        b += 2;
        a++;
    }
    ans[cnt++] = b;
    while(a != 0)
    {
        num = a;
        a = num/-2;
        b = num%-2;
        if(b < 0) {
            b += 2;
            a++;
        }
        ans[cnt++] = b;
    }
    for(int i = cnt-1;i >= 0;i--) printf("%lld",ans[i]);
}