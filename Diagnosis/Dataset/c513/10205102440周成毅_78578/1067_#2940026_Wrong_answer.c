#include <stdio.h>

int main() {
    unsigned long long ll[74];
    ll[0]=0,ll[1]=1,ll[2]=1;
    for(int i=3;i<74;i++)
        ll[i]=ll[i-1]+ll[i-2]+ll[i-3];
    int T;
    scanf("$d",&T);
    for(int i=0;i<T;i++){
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",i);
        printf("%llu\n",ll[n]);
    }
    return 0;
}
