#include <stdio.h>
#include <string.h>

int main()
{
    int out = 1, str1 = 0, str2 = 0, l, i;
    char buff[100];
    while (gets(buff)){
        l = strlen(buff);
        for (i = 0;i < l;i++){
            if (!out){
                if (buff[i] == '*' && buff[i+1] == '/'){
                    out = 1;
                    i += 1;
                }
                continue;
            }else if (buff[i] == '"' && (str2 % 2 == 0)){
                if (buff[i - 1] != '\\'){
                    str1 += 1;
                }else if(buff[i - 2] == '\\'){
                    str1 += 1;
                }
            }else if(buff[i] == '\'' && (str1 % 2 == 0)){
                if (buff[i - 1] != '\\'){
                    str2 += 1;
                }else if(buff[i - 2] == '\\'){
                    str2 += 1;
                }
            }else if (buff[i] == '/'){
                if (str1 % 2 == 1 || str2 % 2 == 1){
                    printf("%c", buff[i]);
                    continue;
                }else if (buff[i + 1] == '/'){
                    break;
                }else if (buff[i + 1] == '*'){
                    out = 0;
                    i += 1;
                    continue;
                }
            }
            printf("%c", buff[i]);
        }
        if (out){
            printf("\n");
        }
    }
    return 0;
}