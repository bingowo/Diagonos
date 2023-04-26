#include <stdio.h>

int main()
{
    char temp1, temp2, temp3, temp4;
    temp1 = getchar();
    while (temp1 != EOF){
        if (temp1 == '/'){  //若读取到/，可能存在行注释也可能有块注释
            temp2 = getchar();
            if (temp2 == '/'){  //读取到行注释的标记
                temp3 = getchar();
                while (temp3 != '\n' && temp3 != EOF){
                    temp3 = getchar();
                }
                if (temp3 == EOF){
                    temp1 = EOF;
                    continue;
                }
                printf("\n");
                temp1 = getchar();
                continue;
            }
            else if (temp2 == '*'){  //读取到块注释的标记
                temp3 = getchar();
                temp4 = getchar();
                while (!(temp3 == '*' && temp4 == '/') && temp3 != EOF && temp4 != EOF){
                    temp3 = temp4;
                    temp4 = getchar();
                }
                if (temp3 == EOF || temp4 == EOF){
                    temp1 = EOF;
                    continue;
                }
                temp1 = getchar();
                continue;
            }
            else {
                printf("%c", temp1);
                temp1 = temp2;
                continue;
            }
        }

        if (temp1 == '\\'){  //若读取到\，输出整个转义字符
            if ((temp2 = getchar()) != EOF){
                printf("%c%c", temp1, temp2);
            }
            temp1 = getchar();
            continue;
        }

        if (temp1 == '\"'){  //若读取到"
            printf("%c", temp1);
            temp2 = getchar();
            while (temp2 != '\"'){
                printf("%c", temp2);
                if (temp2 == '\\'){  //读取到\时，将整个转义字符一起输出，避免将\"识别为"
                    temp3 = getchar();
                    printf("%c", temp3);
                }
                temp2 = getchar();
            }
            printf("%c", temp2);
            temp1 = getchar();
            continue;
        }

        printf("%c", temp1);
        temp1 = getchar();
    }
    return 0;
}