#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char base[64] = {'\0'};
    for(int i = 0; i < 62; i++){
        if(i <= 25) base[i] = 'A' + i;
        else if(i <= 51) base[i] = 'a' + i - 26;
        else if(i <= 61) base[i] = i - 52;
    }
    base[62] = '+';base[63] = '/';


    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){

        char in[101] = {'\0'};
        scanf("%s",in);

        int orinum = strlen(in);
        int cnt = orinum % 3 + orinum / 3 * 4 + 1;

        while(cnt > 0){

        }

    }


    printf("Hello world!\n");
    return 0;
}
