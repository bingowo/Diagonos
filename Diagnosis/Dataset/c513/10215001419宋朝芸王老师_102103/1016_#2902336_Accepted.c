#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    int N,R;
    scanf("%d%d",&N,&R);

    if(N == 0){
        printf("0");
        return 0;
    }

    char ans[20];
    int i = 0;

    while(N != 0){
        int tempS,tempY;
        if(N%R < 0) {
            tempS = N / R + 1;
            tempY = N - tempS*R;
        }
        else {
            tempS = N / R;
            tempY = N % R;
        }
        N = tempS;

        if(tempY > 9) ans[i++] = tempY - 10 + 'A';
        else ans[i++] = tempY + '0';
    }

    i--;
    while(i >= 0) printf("%c",ans[i--]);

    return 0;
}