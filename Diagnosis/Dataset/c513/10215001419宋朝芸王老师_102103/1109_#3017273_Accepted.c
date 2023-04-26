#include <stdio.h>
#include <stdlib.h>

int main()
{
    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){
        printf("case #%d:\n",R);

        int output = 0;
        for(int i = 8; i >= 0; i--){
            int a;
            scanf("%d",&a);

            /***0***/
            //i != 0
            if(a == 0 && i != 0) continue;
            //i == 0
            if(a == 0 && i == 0 && output != 0) continue;
            else if(a == 0 && i == 0) {printf("0");continue;}

            /***for x^0***/
            if(i == 0 && a > 0 && output != 0) {printf("+%d",a);output++;continue;}
            else if(i == 0) {printf("%d",a);output++;continue;}

            /***for x^1***/
            if(i == 1){
                //output == 0
                if(output == 0 && a != 1 && a != -1) {printf("%dx",a);output++;continue;}
                else if(output == 0 && a == 1) {printf("x");output++;continue;}

                else if(a == 1) {printf("+x");output++;continue;}
                else if(a == -1) {printf("-x");output++;continue;}

                //output != 0
                else if(a > 0) {printf("+%dx",a);output++;continue;}
                else if(a < 0) {printf("%dx",a);output++;continue;}
            }

            /***for other***/
            //output == 0
            if(output == 0 && a != 1 && a != -1) {printf("%dx^%d",a,i);output++;continue;}
            else if(output == 0 && a == 1) {printf("x^%d",i);output++;continue;}

            else if(a == 1) {printf("+x^%d",i);output++;continue;}
            else if(a == -1) {printf("-x^%d",i);output++;continue;}

            //output != 0
            else if(a > 0) {printf("+%dx^%d",a,i);output++;continue;}
            else if(a < 0) {printf("%dx^%d",a,i);output++;continue;}
        }

        printf("\n");
    }
    return 0;
}
