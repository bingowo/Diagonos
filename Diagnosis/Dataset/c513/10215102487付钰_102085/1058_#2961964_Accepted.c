#include <stdio.h>
int main()
{
    char c;
    int state=0;
    while((c=getchar())!=EOF){
        switch(state)
        {
            case 0:
                if(c=='/')
                    state=1;
                else if(c=='\'')
                    state=6;
                else if(c=='\"')
                    state=5;
                else
                    printf("%c",c);
                break;
            case 1:
                if(c=='*')
                    state=2;
                else if(c=='/')
                    state=4;
                else
                {
                    printf("/%c",c);
                    state=0;
                }
                break;
            case 2:
                if(c=='*')
                    state=3;
                else
                    state=2;
                break;
            case 3:
                if(c=='/')
                    state=0;
                else if(c=='*')
                    state=3;
                else
                    state=2;
                break;
            case 4:
                if(c=='\n')
                {
                    state=0;
                    printf("%c",c);
                }
                break;
            case 5:
                if(c=='\\')
                    state=8;
                else if(c=='\"')
                {
                    state=0;
                    printf("%c",c);
                }
                break;
            case 6:
                if(c=='\\')
                    state=7;
                else if(c=='\'')
                {
                    state=0;
                    printf("%c",c);
                }
                break;
            case 7:
                state=6;
                break;
            case 8:
                state=5;
                break;
        }
        if(state==5||state ==6||state==7||state==8){
            printf("%c",c);
        }
    }
    return 0;
}