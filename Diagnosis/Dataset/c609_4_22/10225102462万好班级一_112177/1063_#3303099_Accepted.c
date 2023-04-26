#include <stdio.h>
int main(){//你可以走1，2，3，4步
    int loop;scanf("%d",&loop);
    int a;
    long long int ans[51] = {1,2,4,8};
    for (int i = 0; i < loop; ++i)
    {
        scanf("%d",&a);
        for (int i = 4; i < 51; ++i) {
            ans[i] = ans[i-1] + ans[i-2] + ans[i-3] + ans[i-4];
        }
        printf("case #%d:\n%lld\n",i,ans[a-1]);}
}
