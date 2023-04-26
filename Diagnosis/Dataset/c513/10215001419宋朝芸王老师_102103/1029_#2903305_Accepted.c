#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,R;
    scanf("%d",&T);
    for(R = 0; R < T; R++){

        /*char input[201][201];
        int i = 0, j = 0;
        char temp;
        while((temp = getchar()) != EOF && temp != '\n'){
            if(temp == ' '){
                input[i++][j] = '\0';
                j = 0;
                temp = getchar();
            }
            else input[i][j++] = temp;
        }
        input[i++][j] = '\0';*/

        int index[255] = {0};
        char str[201];
        if(R==0) getchar();/***过滤scanf的回车***/
        gets(str);

        char *ps = str;
        while(*ps){
            if(*ps <='Z' && *ps >= 'A') index[*ps]++;
            ps++;
        }

        ps = str;
        int *pi = &index['A'];
        while(*ps){
            if(*ps <='Z' && *ps >= 'A'){
                while(*pi == 0) pi++;
                if(*pi != 0){
                    *ps = pi - index;
                    (*pi)--;
                }
            }
            ps++;
        }

        printf("case #%d:\n%s\n",R,str);
    }
    return 0;
}
