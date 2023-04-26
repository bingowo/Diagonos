#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long choices(int n, int begin, int end, int time){
    if(abs(end-begin) > time || time==0) return 0;
    if(abs(end-begin) == time) return 1;
    if(begin == 1) return choices(n, 2, end, time-1);
    if(begin == n) return choices(n, n-1, end, time-1);
    return choices(n, begin+1, end, time-1)+choices(n, begin-1, end, time-1);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0; i<T; ++i) {
        int n, p, m, t;
        //n-allcnt p-begin m-time t-end
        scanf("%d %d %d %d",&n, &p, &m, &t);
        printf("%lld\n",choices(n, p, t, m));
    }
    return 0;
}