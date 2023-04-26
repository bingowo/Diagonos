#include <stdio.h>
int main(){//你可以走1，2，3，4步
    int a;
    scanf("%d",&a);
    long long int ans[51] = {1,2,4,8};
    for (int i = 4; i < 51; ++i) {
        ans[i] = ans[i-1] + ans[i-2] + ans[i-3] + ans[i-4];
    }
    printf("%lld",ans[a-1]);
}
