#include <stdio.h>
int main()
{
    char ch=getchar();
    int flag = 0;
    while(ch!=EOF)
    {
        switch(flag)
        {
            case 0:
                if(ch=='\'')
                {
                    flag=2;putchar(ch);
                }
                else if(ch == '"')
                {
                    flag = 1;putchar(ch);
                }
                else if(ch=='/')
                {
                    flag=3;
                }
                else putchar(ch);
                break;
            case 1:
                if(ch=='\\') flag=7;
                else if(ch=='"') flag=0;
                putchar(ch);
                break;
            case 2:
                if(ch=='\'')
                {
                    flag=0;
                }
                putchar(ch);
                break;
            case 3:
                if(ch=='/')
                {
                    flag=5;
                }
                else if(ch=='*')
                {
                    flag=4;
                }
                else
                {
                    flag=0;putchar(ch);
                }
                break;

            case 4:
                if(ch=='*') flag=6;
                break;
            case 5:
                if(ch=='\n')
                {
                    flag=0;putchar(ch);
                }
                break;
            case 6:
                if(ch=='*') flag=6;
                else if(ch=='/') flag=0;
                else flag=4;
                break;
            case 7:
                putchar(ch);
                flag=1;
                break;
        }
       ch=getchar();
    }
    return 0;
}
