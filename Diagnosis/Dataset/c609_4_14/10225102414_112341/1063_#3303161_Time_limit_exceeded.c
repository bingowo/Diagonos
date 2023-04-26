#include <stdio.h>
long long cal(int n){ return n > 4 ? cal(n - 4) + cal(n - 3) + cal(n - 2) + cal(n - 1) : n == 4 ? 8 : n == 3 ? 4 : n == 2 ? 2 : 1;}
int main()
{
    int T, cas = 0;
    for (scanf("%d", &T);T != 0;T--){
        int n;scanf("%d", &n);
        printf("case #%d:\n%lld\n", cas++, cal(n));
    }
    return 0;
}
