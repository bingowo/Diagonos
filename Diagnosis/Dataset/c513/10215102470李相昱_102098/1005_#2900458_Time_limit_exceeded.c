#include <stdio.h>
#include <string.h>
int main() {
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        char Octal[55], Decimal[155] = {};
        scanf("s",Octal);
        int len = strlen(Octal);
        int last = 0;
        int m;
        int j;
        Decimal[0] = '0';
        Decimal[1] = '.';
        for(;len!=2;len--){
            for(j=2;last!=0||j<len;j++){
                if(j<len){
                    m = Octal[j] -'0';

                }
                else{
                    m=0;
                }
                Decimal[j] = (last *10 +m)/8 +'0';
                last = last *10 +m - (Decimal[j] - '0');
            }
            len = j;
        }

        printf("case #%d:\n",i);
        for(int p=0;p<len;p++){
            printf("%c",Decimal[p]);
        }
    }

    return 0;
}
