#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int m,n;
        scanf("%d%d",&m,&n);
        int ans = 0;
        for(int i=0;i<32;i++){
            int temp = (m&1) ^ (n&1);
            if(temp == 1)ans++;
            m = m >> 1;
            n = n >> 1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
