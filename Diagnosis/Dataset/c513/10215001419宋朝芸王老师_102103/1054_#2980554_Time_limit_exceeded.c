//⌂
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

        WORDS w[2001];
        int wcnt = 0;
        int lcnt = 0;
        int width;
        char c;

        scanf("%d",&width);
        getchar();

        /***input***/
        while((c = getchar()) != '\n'){
            if(c != ' '){
                w[wcnt].s[lcnt++] = c;
            }

            if(c == ' '){
                w[wcnt].s[lcnt] = ' ';
                w[wcnt++].len = lcnt; //actual
                lcnt = 0;
            }
        }
        w[wcnt].s[lcnt] = ' ';
        w[wcnt].len = lcnt;


        /***output***/
        printf("case #%d:\n",R);

        int i;
        while(i <= wcnt){
            int j = 0;
            int spaces[70] = {0};
            int scnt = 0;

            //i for all words, j for words in a line
            //lcnt for words len in a line, scnt for spaces in a line


            while(w[i+j].len <= 10 - lcnt - scnt){
                    lcnt += w[i+j].len;
                    spaces[j]++;
                    scnt++;j++;
            }
            scnt--;

            int k = scnt;
            if(lcnt + scnt < 10){
                spaces[k--]++;
                scnt++;
            }

            k = 0;
            while(k < j){
                printf("%s",w[i+k].s);
                while(spaces[k] > 0)
                    printf("⌂");
            }
            printf("\n");

            i += j;
        }
    }

    return 0;
}

