#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){
        char s[101];
        scanf("%s",s);

        int len = strlen(s);
        int black[4] = {0};

        //find the seq
        char seq[4] = {'\0'};
        int check = 0;
        for(int i = 0; i < len/4 && check < 4; i++){
            for(int j = 0; j < 4 && check < 4; j++){
                if(s[i*4 + j] != '!') {
                    seq[j] = s[i*4+j];
                    check++;
                }
            }
        }
        for(int i = 0; i < len%4 && check < 4; i++){
            if(s[len-len%4+i] != '!'){
                seq[i] = s[len-len%4+i];
                check++;
            }
        }

        //cal the black
        for(int i = 0; i < len/4; i++){
            for(int j = 0; j < 4; j++){
                if(s[i*4 + j] == '!') {
                    black[j]++;
                }
            }
        }
        for(int i = 0; i < len%4; i++){
            if(s[len-len%4+i] == '!'){
                black[i]++;
            }
        }

        //output
        printf("case #%d:\n",R);
        for(int i = 0; i < 4; i++){
            if(seq[i] == 'R'){
                printf("%d ",black[i]);
            }
        }
        for(int i = 0; i < 4; i++){
            if(seq[i] == 'B'){
                printf("%d ",black[i]);
            }
        }
        for(int i = 0; i < 4; i++){
            if(seq[i] == 'Y'){
                printf("%d ",black[i]);
            }
        }
        for(int i = 0; i < 4; i++){
            if(seq[i] == 'G'){
                printf("%d\n",black[i]);
            }
        }

    }
    return 0;
}
