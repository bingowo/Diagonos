#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define N 65

int main()
{

    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){
        long long int n;
        scanf("%lld",&n);

        //special case
        if(n == 1 || n == 2) {printf("%lld is powerless.\n",n);continue;}

        //other cases
        int flag = 0;   //have not output yet
        for(int i = 2; i <= N; i++){
            int a = (int)pow(n,1.0/i);
            if(pow(a,i) == n || pow(a+1,i) == n || pow(a-1,i) == n){
                if(flag == 0) printf("%lld=%d^%d",n,a,i);
                else printf("=%d^%d",a,i);
                flag = 1;
            }
        }

        if(flag == 0) {printf("%lld is powerless.\n",n);continue;}

        printf("\n");
    }

    return 0;
}
