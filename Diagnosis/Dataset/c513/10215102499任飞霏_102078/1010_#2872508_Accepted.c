#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    char str[510];
    scanf("%s",str);
    int len = strlen(str);
    printf("0001");
    for(int i = 9;i >= 0;i--){
        printf("%d",len>>i&1);

    }
    int a = 0,number = 0;
    while(len > 0){

        if(len != 2 && len != 1){
            //printf("%d\n",str[a] - '0');
            number = (str[a++] - '0')*100 + (str[a++] - '0')*10 + (str[a++] - '0');
            //printf("%d\n",number);
            for(int i = 9;i >= 0;i--){
                printf("%d",number>>i&1);
        }
        }
        else if(len == 2){
            number = (str[a++] - '0')*10 + (str[a++] - '0');
            for(int i = 6;i >= 0;i--){
                printf("%d",number>>i&1);
            }
        }
        else if(len == 1){
            number = (str[a++] - '0');
            for(int i = 3;i >= 0;i--){
                printf("%d",number>>i&1);
            }

        }
        len -= 3;
    }

    return 0;
}


