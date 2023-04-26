#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define N 10000

int main()
{
    char com[N] = {'\0'};
    int len;    //len of com
    char a;     //every char
    int times = 0;  //how many times
    int flag = 0;

    while(scanf("%c",&a) != EOF && a != '\n'){

        if(flag == 0 && isalpha(a)){
            //output previous combination
            for(int i = 0; i < times; i++)
                printf("%s",com);

            //start new combination
            flag = 1;
            len = 0;
            memset(com,0,N);
            com[0] = a;
        }
        else if(flag == 1 && isalpha(a)){
            com[++len] = a;
        }
        else if(flag == 1 && isdigit(a)){
            flag = 0;
            times = 0;
            times = a - '0';
        }
        else if(flag == 0 && isdigit(a)){
            times = times*10 + a - '0';
        }
    }

    if(flag == 1) printf("%s",com);

    else if(times > 0){
        for(int i = 0; i < times; i++)printf("%s",com);
    }

    return 0;
}
