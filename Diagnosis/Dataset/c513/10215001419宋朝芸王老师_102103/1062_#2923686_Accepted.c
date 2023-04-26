#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int steps[51] = {0};
    steps[1] = 1;
    steps[2] = 2;
    steps[3] = 4;
    steps[4] = 8;
    int most = 4;

    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){
        int i;
        scanf("%d",&i);

        if(i <= most){
            printf("case #%d:\n%lld\n",R,steps[i]);
        }
        else{
            for(int k = most+1; k <= i; k++){
             steps[k] = steps[k-1] + steps[k-2]
                + steps[k-3] + steps[k-4];
            }
            printf("case #%d:\n%lld\n",R,steps[i]);
        }
    }

    return 0;
}
