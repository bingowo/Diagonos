#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int t = 0; t <T; t++){
        int n, p, m,t;
        scanf("%d %d %d %d",&n,&p,&m,&t);
        int a,b;
        a = (m + t - p) / 2;
        b = (m - t + p) / 2;
        int ans = 0;
        if(a + b != m){
            printf("0\n");
            return 0;
        }else if (a == 0 || b == 0){
            printf("1\n");
            return 0;
        }
    }
    return 0;
}
