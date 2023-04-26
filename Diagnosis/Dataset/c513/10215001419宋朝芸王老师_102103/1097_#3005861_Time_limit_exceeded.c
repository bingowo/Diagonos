#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 85
int main()
{
    char s[M] = {0};
    while(scanf("%s",s)){
        int len = strlen(s);
        if(len == 1){printf("%s\n",s);continue;}

        //count row & column
        int row = 0, col = len;
        int posRow = 0, rowUp = 0, rowDown = 0;

        for(int i = 1; i < len; i++){
            if(s[i] > s[i-1]){
                posRow++;
                if(posRow > rowUp) rowUp++;
            }
            if(s[i] < s[i-1]){
                posRow--;
                if(posRow < rowDown) rowDown--;
            }

        }

        //put elements into array
        char output[M][M];
        memset(output,0,M*M);

        row = rowUp - rowDown + 1;
        posRow = rowUp;

        output[posRow][0] = s[0];
        for(int i = 1; i < len; i++){
            if(s[i] > s[i-1]){
                posRow--;
                output[posRow][i] = s[i];
            }
            else if(s[i] < s[i-1]){
                posRow++;
                output[posRow][i] = s[i];
            }
            else if(s[i] == s[i-1]){
                output[posRow][i] = s[i];
            }
        }

        //put spaces
        for(int i = 0; i < row; i++){
            int flag = 0;
            for(int j = col-1; j >= 0; j--){
                if(output[i][j] == '\0' && flag == 0) flag = 1;
                else if(output[i][j] == '\0') output[i][j] = ' ';
            }
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                printf("%c",output[i][j]);
            }
            printf("\n");
        }


        memset(s,0,M);
    }
    return 0;
}
