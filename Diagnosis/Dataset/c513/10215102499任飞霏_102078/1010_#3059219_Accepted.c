#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[510] = {};
    scanf("%s",s);

    printf("0001");
    int len = strlen(s);

    for(int i=9;i>=0;i--){
        printf("%d",len>>i&1);
    }

    int a=0,number=0;
    while(len>0){
        if(len>2){
            number = (s[a++]-'0')*100 + (s[a++]-'0')*10 + s[a++]-'0';
            for(int i=9;i>=0;i--){
                printf("%d",number>>i&1);
            }
        }

        else if(len==2){
            number = (s[a++]-'0')*10 + s[a++] - '0';
            for(int i=6;i>=0;i--){
                printf("%d",number>>i&1);
            }
        }

        else if(len == 1){
            number = s[a] - '0';
            for(int i=3;i>=0;i--){
                printf("%d",number>>i&1);
            }
        }

        len -= 3;
    }
    return 0;
}
