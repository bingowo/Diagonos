#include <stdio.h>
#include <string.h>
int main() {
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        char Octal[55] = {0}, Decimal[155] = {0};
        scanf("%s",Octal);
        int numbers = 0,j,temp;
        int len = strlen(Octal)-1;
        for(;len!=1;--len){
            int digit = Octal[len] -'0';
            j =0;
            do {
                if (j < numbers) {
                    temp = digit * 10 + Decimal[j] - '0';
                } else {
                    temp = digit * 10;
                }
                Decimal[j++] = temp / 8 + '0';
                digit = temp % 8;
            } while (digit != 0|| j<numbers);
            numbers = j;
        }
        Decimal[numbers] = 0;
        printf("case #%d:\n",i);
        printf("0.%s\n",Decimal);
    }
    return 0;
}
