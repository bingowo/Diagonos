#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int cmp (const void *a, const void *b){
    //char *pa = *(char**)a, *pb = *(char**)b;
    return strcmp((char*)a,(char*)b);
}

int main()
{
    int R,T;
    scanf("%d",&T);
    getchar();

    for(R = 0; R < T; R++){
        char c = getchar();
        char words[501][501] = {'\0'};
        int i = 0, j = 0;


        while(c != '\n' && c != EOF){
            if(c == ' ' || c == '!' ||
            c == ',' || c == '.' || c == '?'){
                //words[i++][j] = '\0';
                i++;
                j = 0;
                c = getchar();
            }
            while(c == ' ' || c == '!' ||
            c == ',' || c == '.' || c == '?'){
                c = getchar();
            }
            /*while(c == ' ' || c == '!' ||
            c == ',' || c == '.' || c == '?') c = getchar();*/
            while(isalpha(c)){
                words[i][j++] = c;
                c = getchar();
            }

        }
        //words[i++][j] = '\0';

        qsort(words,i,sizeof(words[0]),cmp);

        printf("case #%d:\n%s",R,words[0]);
        char temp[501];
        int k = 0;
        while(k < i){
            strcpy(temp,words[k]);
            k++;
            while(strcmp(temp,words[k]) == 0) k++;
            printf(" %s",words[k]);
        }
        printf("\n");
    }
    return 0;
}
