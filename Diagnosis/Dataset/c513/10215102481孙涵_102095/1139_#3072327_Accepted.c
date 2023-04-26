#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A;
    scanf("%d",&A);
    int ans = A * 2;
    int a,b,d;
    b = 10;
    int flag = -1;
    while(ans < 10000 * A){
        //a / b = c ...... d
        a = ans;
        b = 10;
        d = a % b;
        while(a > 0){
            if(d > 1){
                flag = 0;
            }else{
                a = a / b;
                d = a % b;
            }
            if (flag == 0){
                goto label;
            }
        }

        if (a == 0){
            flag = 1;
            break;
        }
        label:
        ans = ans + A;
        flag = -1;

    }
    if (flag == 1){
        printf("%d",ans);
    }else{
        printf("-1");
    }
    return 0;
}
