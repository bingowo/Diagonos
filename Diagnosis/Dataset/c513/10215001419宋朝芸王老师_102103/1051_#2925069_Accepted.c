#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    /***index***/
    char base[64] = {'\0'};
    for(int i = 0; i < 62; i++){
        if(i <= 25) base[i] = 'A' + i;
        else if(i <= 51) base[i] = 'a' + i - 26;
        else if(i <= 61) base[i] = '0' + i - 52;
    }
    base[62] = '+';base[63] = '/';



    /***start***/
    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){

        /***input***/
        char in[101] = {'\0'};
        int bin[809] = {0};
        scanf("%s",in);

        int orinum = strlen(in);


        /***intobinary***/
        for(int k = 0; k < orinum; k++){
            char c = in[k];
            for(int m = 0; m < 8; m++){
                bin[k * 8  + 7 - m] = c % 2;
                c = c / 2;
            }
        }


        /***output***/
        printf("case #%d:\n",R);

        int cnt;
        if(orinum % 3 == 0) cnt = orinum / 3 * 4;
        else cnt = orinum % 3 + orinum / 3 * 4 + 1;
        int i = 0;

        while(cnt > 0){
            int temp_char = 0;
            for(int j = 0; j < 6; j++){
                temp_char = temp_char * 2 + bin[i * 6 + j];
            }
            printf("%c",base[temp_char]);
            i++;
            cnt--;
        }

        /***output sth more***/
        if(orinum % 3 == 1) printf("==\n");
        else if(orinum % 3 == 2) printf("=\n");
        else printf("\n");

    }

    return 0;
}
