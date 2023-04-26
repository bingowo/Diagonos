#include <stdio.h>

#define OUT 0
#define INBLOCKCOMMENT 1
#define INLINECOMMENT 2
#define INSTRI 3
#define INCHAR 4
#define IBC INBLOCKCOMMENT
#define ILC INLINECOMMENT
#define IS INSTRI
#define IC INCHAR
using namespace std;

int main()
{
    short state=OUT;
    short cntbackslash=0,followbackslash=0;
    short followforwslash=0,followasterisk=0;
    char c=0;
    while(c=getchar()!=EOF)
    {   putc(c,stdin);
        if(followbackslash>0) followbackslash--;
        if(followforwslash&&c!='/'&&c!='*')
        {
            printf("/");
            followforwslash=0;
        }
        else if(followforwslash)
        {
            if(c=='/')
                state=ILC;
            if(c=='*')
                state=IBC;
            followforwslash=0;
        }
        if(followasterisk&&c!='/')
            followasterisk=0;
        switch(state)
        {
            case OUT:
                switch(c)
                {
                    case '"':
                        state=IS;
                        printf("%c",c);
                        break;
                    case '\'':
                        state=IC;
                        printf("%c",c);
                        break;
                    case '/':
                        followforwslash=1;
                        getchar();
                        break;
                    default:
                        printf("%c",c);
                        break;
                }
                break;
            case IS:
                if(c=='\\')
                {
                    cntbackslash++;
                    followbackslash=2;
                }
                else if(c=='"'&&(!(cntbackslash%2)||!followbackslash))
                {
                    cntbackslash=0;
                    state=OUT;
                }
                else if(c=='"')
                    cntbackslash--;
                printf("%c",c);
                break;
            case IC:
                if(c=='\\')
                {
                    cntbackslash++;
                    followbackslash=2;
                }
                else if(c=='\''&&(!(cntbackslash%2)||!followbackslash))
                {
                    cntbackslash=0;
                    state=OUT;
                }
                else if(c=='\'')
                    cntbackslash--;
                printf("%c",c);
                break;
            case ILC:
                if(c=='\n')
                {
                    printf("%c",c);
                    state=OUT;
                }
                else
                    getchar();
                break;
            case IBC:
                if(c=='*')
                {
                    followasterisk=1;
                    getchar();
                }
                else if(followasterisk)
                {
                    getchar();
                    state=OUT;
                }
                else
                    getchar();
                break;
            default:
                cout<<"wrong state"<<endl;
                break;
        }
    }
    return 0;
}
