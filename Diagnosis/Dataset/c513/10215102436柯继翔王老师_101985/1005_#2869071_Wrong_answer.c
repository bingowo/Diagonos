#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    char octal[55], decimal[155];
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        scanf("%s", octal);
        int num_d = 0,temp, remainder, n;
        for(int j = strlen(octal) - 1;j >=2 ;j--){
            remainder = octal[j] - '0';
            n = 0;
            temp = 0;
            do{
                if(n < num_d){
                    temp = remainder * 10 + decimal[n] - '0';
                }else{
                    temp = remainder * 10;
                }
                decimal[n++] = temp / 8 + '0';
                remainder = temp % 8;
            }while(n < num_d || remainder != 0);
            num_d = n;
        }
        decimal[n] = 0;
        printf("case #%d\n",i);
        printf("0.%s\n",decimal);
    }
    return 0;
}
