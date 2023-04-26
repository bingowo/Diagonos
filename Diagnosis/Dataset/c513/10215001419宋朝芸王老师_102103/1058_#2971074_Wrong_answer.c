#include <stdio.h>
#include <stdlib.h>

int main()
{
    int start = 0;
    int star = 0;
    int quote = 0;
    char c;

    while((c = getchar()) != EOF){

        if(c == '"'){
            quote += 1;
        }

        else if(c == '/' && quote == 0){
            if(start == 0) start += 1;
            else if(start == 1 && star == 2) {star = 0;start = 0;continue;}
            else if(start == 1) start += 1;
        }

        else if(c == '*'){
            if(start == 1) star += 1;
        }

        else if(c == '\n'){
            if(start == 2) start = 0;
        }

        else if(c == ';'){
            start = 0;
            star = 0;
            quote = 0;
        }

        if(quote == 0 && start != 0) continue;
        else putchar(c);
    }
    return 0;
}