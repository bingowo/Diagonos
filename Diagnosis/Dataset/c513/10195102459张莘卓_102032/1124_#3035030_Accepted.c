#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int simple(int a, int b) {
    while(b) {
        int t = a % b; a = b; b = t;
    }
    return a==1;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        int n, num[1001]={0};
        scanf("%d",&n);
        for(int i=0; i<n; ++i) {
            int t;
            scanf("%d",&t);
            num[t] = 1;
        }
        int a[1000]={0}, cnt=0, ans=0;
        for(int i=1; i<1001; ++i)
            if(num[i]) a[cnt++] = i;
        for(int i=0; i<cnt; ++i)
            for(int j=i+1; j<cnt; ++j)
                if(simple(a[i], a[j])) ++ans;
        printf("case #%d:\n%d\n",j,ans);
    }
    return 0;
}
