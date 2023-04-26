#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char ans[2002] = {'\0'};
    int str = 1000, end = 1000;

    char c = getchar();
    char temp = toupper(c);
    ans[str] = temp;

    while((c = getchar()) != '\n' && c != EOF){
        if(toupper(c) < temp){
            ans[++end] = toupper(c);
        }
        else{
            temp = toupper(c);
            ans[--str] = temp;
        }
    }

        printf("%s",ans+str);

    return 0;
}
