#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    char c;
    int state=0;
    while((c=getchar())!=EOF){
        switch(state){
            case 0:{
                if(c=='/')state=1;
                else if(c=='\''){state=5;putchar(c);}
                else if(c=='"'){state=6;putchar(c);}
                else putchar(c);
                break;
            }
            case 1:{
                if(c=='/')state=2;
                else if(c=='*')state=3;
                else putchar(c);
                break;
            }
            case 2:{
                if(c=='\n')state=0;
                putchar(c);
                break;
            }
            case 3:{
                if(c=='*')state=4;
                break;
            }
            case 4:{
                if(c=='/')state=0;
                else if(c=='*')state=4;
                else state=3;
                break;
            }
            case 5:{
                if(c=='\\')state=7;
                else if(c=='\'')state=0;
                putchar(c);
                break;
            }
            case 6:{
                if(c=='\\')state=8;
                else if(c=='"')state=0;
                putchar(c);
                break;
            }
            case 7:{
                state=5;
                putchar(c);
                break;
            }
            case 8:{
                state=6;
                putchar(c);
                break;
            }
        }
    }
    return 0;
}
