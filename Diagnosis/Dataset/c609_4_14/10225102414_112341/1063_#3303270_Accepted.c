#include <stdio.h>
int main()
{
    int T, cas = 0;
    for (scanf("%d", &T);T != 0;T--){
        int n;scanf("%d", &n);
        long long O[4] = {1, 2, 4, 8}, temp;
        for (int i = 4;i < n;i++){
            temp = O[0] + O[1] + O[2] + O[3];
            O[0] = O[1];O[1] = O[2];O[2] = O[3];O[3] = temp;
        }
        printf("case #%d:\n%lld\n", cas++, n > 4 ? O[3] : O[n - 1]);
    }
    return 0;
}
