#include <stdlib.h>
#include <stdio.h>

int coef[4] = {1, 2, 3, 4};

int main(){
    int T = 0;
    scanf("%d", &T);
    for(int i = 0;i<T;++i){
        int n = 0, ans = 0;
        scanf("%d", &n);
        for(int i1 = 0;i1<=n;i1++){
            int n_cpy = n;
            n_cpy -= i1;
            for(int i2 = 0;i2<=n;i2++){
                n_cpy -= 2*i2;
                for(int i3 = 0;i3<=n;i3++){
                    n_cpy -= 3*i3;
                    for(int i4 = 0;i4<=n;i4++){
                        n_cpy -= 4*i4;
                        if(i1 + 2*i2 + 3*i3 + 4*i4 == n){
                            ans++;
                        }
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
}
