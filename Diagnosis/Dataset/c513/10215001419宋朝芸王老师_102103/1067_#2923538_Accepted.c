#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long T[75] = {0};
    T[0] = 0;
    T[1] = 1;
    T[2] = 1;
    T[3] = 2;
    int most = 3;

    int R,K;
    scanf("%d",&K);
    for(R = 0; R < K; R++){
        int i;
        scanf("%d",&i);

        printf("case #%d:\n",R);

        if(i <= most) {
            printf("%lld\n",T[i]);
        }

        else{
            for(int j = most+1; j <= i; j++){
                T[j] = T[j-1] + T[j-2] + T[j-3];
            }
            most = i;
            printf("%lld\n",T[i]);
        }
    }

    return 0;
}
