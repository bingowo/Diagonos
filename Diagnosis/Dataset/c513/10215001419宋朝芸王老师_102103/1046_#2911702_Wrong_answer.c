#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int R,T;
    scanf("%d",&T);
    getchar();

    char del[6][4]={{"the"},{"a"},{"an"},{"of"},
        {"for"},{"and"}};

    for(R = 0; R < T; R++){
        char input[101][101];
        int num = 0;
        int i = 0, j = 0;

        char c;
        while((c = getchar()) != '\n' && c != EOF){
            if(c == ' '){
                input[i++][j] = '\0';
                j = 0;
                c = getchar();
            }
            while(c == ' ') c = getchar();
            if(isalpha(c)) input[i][j++] = c;
        }
        input[i++][j] = '\0';


        int flag = 0;
        for(int k = 0; k < i; k++){
            for(int j = 0; j < 6; j++){
                if(strcmp(del[j],input[k])== 0) {flag = 1;break;}
            }
            if(flag == 0) num++;
            flag = 0;
        }

        printf("case #%d:\n%d\n",R,num);
    }

    return 0;
}
