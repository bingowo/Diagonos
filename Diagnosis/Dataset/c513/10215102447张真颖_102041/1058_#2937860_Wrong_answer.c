#include <stdio.h>
#include <stdlib.h>

int status1(char ch)
{
    if(ch=='"') return 1;
    else if(ch!='"') return 2;
}
int status2(char ch)
{
    if(ch=='/') return 1;
    else if(ch!='*') return 2;
    else if(ch=='*') return 3;
}

int main()
{
    char ch;
    while((ch=getchar())!=EOF)
    {
        if(status1(ch)==1)
        {
            printf("%c",ch);
            ch=getchar();
            while(status1(ch)!=1)
                printf("%c",ch),ch=getchar();
            printf("%c",ch);
        }
        else if(status2(ch)==1)
        {
            ch=getchar();
            int cnt=0;
            while(status2(ch)!=1)
            {
                ch=getchar();
                cnt++;
            }
            if(cnt==0)
            {
                while(ch!='\n')
                    ch=getchar();
                printf("\n");
            }

        }
        else printf("%c",ch);
    }
    return 0;
}