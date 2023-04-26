#include <stdio.h>
int main() {
    int T;
    scanf("%d",&T);
    while (T--){
        int n;
        scanf("%d",&n);
        int ret=0;
        while(n>=0){
            int n1=n;
            while (n1>=0){
                int n2=n1;
                ret = ret+(n2/2+1);
                n1-=3;
            }
            n-=4;
        }
        printf("%d\n",ret);
    }
    return 0;
}
