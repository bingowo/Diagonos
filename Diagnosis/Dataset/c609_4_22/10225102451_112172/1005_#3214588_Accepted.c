#include <stdio.h>
#include <stdlib.h>

int main()
{

    int t;
    scanf("%d",&t);
    int i=0;
    char *s;
    char input[1000];
    int answer=0;
    for(;i<t;i++){
        scanf("%s",input);
        s=input;
        answer=0;
        while(*s!='\0')
        {
            if (*s=='1')
                answer=(answer+1)*3;

            else if(*s=='-')
                answer=(answer-1)*3;

            else
                answer=answer*3;

            s++;
        }
        answer/=3;
        printf("case #%d:\n%d\n",i,answer);


    }
    return 0;
}