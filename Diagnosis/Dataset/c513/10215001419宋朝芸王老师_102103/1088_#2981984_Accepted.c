#include <stdio.h>
#include <stdlib.h>

int main()
{
    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){
        int m,n;
        scanf("%d%d",&m,&n);
        if(n > m-n) n = m - n;

        unsigned long long int ans = 1;
        unsigned int large = m-n, small = n;
        for(int i = m; i > large; i--){
            if(i == 2*small){
                ans *= 2;
                small--;
            }
            else ans *= i;
        }
        while(small > 1){
            ans /= small;
            small--;
        }
        printf("case #%d:\n%lld\n",R,ans);
    }
    return 0;
}
