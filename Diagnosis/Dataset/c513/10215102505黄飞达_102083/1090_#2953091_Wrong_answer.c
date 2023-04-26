#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    while (1){
        int num1=0;
        scanf("%d", &num1);
        if (num1==0) break;
        double num2 = num1*log10(num1*1.0);
        // num2 -= (int)num2;
        double res = pow(10, num2);
        char c[101]={0};
        gcvt(res, 100, c);
        printf("%c\n", c[0]);
    }
    return 0;
}