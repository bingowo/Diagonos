#include <stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0; t<T; ++t) {
        int n, m, i = 0;
        scanf("%d %d",&n, &m);
        int mod = n, a[100]={0}, num[100]={0};
        while(mod) {
            if(a[mod]) break;
            a[mod] = i + 1;
            num[i++] = mod * 10 / m;
            mod = mod * 10 % m;
        }
        printf("case #%d:\n0.",t);
        for(int k=0; k<i; ++k)
            printf("%d",num[k]);
        printf("\n");
        if(mod) printf("%d-%d\n",a[mod],i);
    }
    return 0;
}
