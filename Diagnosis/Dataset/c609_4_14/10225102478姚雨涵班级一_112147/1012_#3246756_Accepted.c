#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 0;i<t;i++){
        printf("case #%d:\n",i);
        char oct[55],deci[160];
        scanf("%s",&oct);
        int number = 0,len = strlen(oct) - 1;
        for(;len > 1;len--){
            int temp,j = 0;
            int digit = oct[len] - '0';
            do{
                if(j < number)
                    temp = digit*10 + deci[j] - '0';
                else
                    temp = digit*10;
                deci[j++] = temp/8 + '0';
                digit = temp % 8;
            }while(j < number||digit != 0);
            number = j;
        }
        deci[number] = '\0';

        printf("0.%s\n",deci);
    }
    return 0;
}
