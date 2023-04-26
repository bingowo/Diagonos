#include <stdio.h>
#include <stdlib.h>


typedef struct{
    char s[36];
    int len;
}WORDS;

int main()
{
    int T;
    scanf("%d",&T);

    for(int R = 0; R < T; R++){

        WORDS *w = (WORDS*)malloc(2001*sizeof(WORDS));
        int wcnt = 0;
        int lcnt = 0;
        int width;

        scanf("%d",&width);
        getchar();


        /***input***/
        char c = getchar();
        while(c != '\n'){
            if(c != ' '){
                w[wcnt].s[lcnt++] = c;
            }

            else if(c == ' ' && lcnt != 0){
                w[wcnt].s[lcnt] = '\0';
                w[wcnt++].len = lcnt; //actual
                lcnt = 0;
            }
            c = getchar();
        }
        w[wcnt].s[lcnt] = '\0';
        w[wcnt++].len = lcnt;


        /***process_by_lines***/
        printf("case #%d:\n",R);
        int i = 0;

        while(i < wcnt){
            int j = 0;
            int spaces[70] = {0};
            int scnt = 0;
            lcnt = 0;
            //i for all words, j for words in a line
            //lcnt for words len in a line, scnt for spaces in a line

        /***cal***/
            while(i + j < wcnt && w[i+j].len <= width - lcnt - j){
                lcnt += w[i+j].len;
                spaces[j]++;
                j++;
            }
            scnt = j - 1;


        /***not the last line***/
            if(i + j != wcnt){

                /***recal_spaces***/
                int add = (width - lcnt - scnt) / scnt;
                for(int k = 0; k < j - 1; k++){
                    spaces[k] += add;
                    scnt += add;
                }

                for(int k = j - 2; lcnt + scnt < width; k--){
                    spaces[k]++;
                    scnt++;
                }

                /*
                int add = (width - lcnt - scnt) / scnt;
                int temp = (width - lcnt - scnt) % scnt;
                while(lcnt + scnt < width){
                    spaces[k--] += add;
                    scnt += add;

                    if(temp != 0 && k >= scnt - temp){
                        spaces[k--] ++;
                        scnt ++;
                    }
                }*/

                /***output***/
                for(int k = 0;k < j; k++){
                    printf("%s",w[i+k].s);
                    while(spaces[k] > 0){
                        printf(" ");
                        spaces[k]--;
                    }
                }
                printf("\n");
            }

        /***the last line***/
            else{
                for(int k = 0; k < j; k++){
                    printf("%s",w[i+k].s);
                    if(k != j - 1){
                        printf(" ");
                    }
                }
                printf("\n");
            }

            i += j;
        }
    }


    return 0;
}
