#include <stdio.h>
#include <stdlib.h>

int main()
{
    int start = 0;
    int quote = 0;
    char c;
    char temp;

    while((c = getchar()) != EOF){

        if(c == '"'){
            if(quote == 0) quote += 1;
            else quote -= 1;
        }

        else if(c == '/' && quote == 0){
            temp = getchar();

            if(temp == '*' && start == 0) {start = 1;continue;}
            else if(temp == '*' && start == 1) {start = 0;continue;}
            else if(temp == '/' && start == 0) {start = 2;continue;}
            else{putchar(c);putchar(temp);continue;}
        }

        else if(c == '\n'){
            if(start == 2) start = 0;
        }

        if(start == 0) putchar(c);
    }
    return 0;
}