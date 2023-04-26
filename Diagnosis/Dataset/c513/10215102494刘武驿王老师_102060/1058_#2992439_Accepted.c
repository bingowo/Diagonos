#include<stdio.h>
#include<string.h>
int main()
{
	int state = 0;
	char ch;
	while ((ch=getchar())!=EOF)
    {
        if (state==0)
        {
            if (ch=='/') state = 1;
            else if (ch=='\"') {state = 5; printf("%c",ch);}
            else if (ch=='\'') {state = 7; printf("%c",ch);}
            else printf("%c",ch);
        }
        else if (state==1)
        {
            if (ch=='/') state = 4;
            else if (ch=='*') state = 2;
            else {printf("/%c",ch); state = 0;}
        }
        else if (state==2)
        {
            if (ch=='*') state = 3;
        }
        else if (state==3)
        {
            if (ch=='/') state = 0;
            else if (ch=='*') ;
            else state = 2;
        }
        else if (state==4)
        {
            if (ch=='\n') {printf("\n"); state = 0;}

        }
        else if (state==5)
        {
            if (ch=='\"') {printf("%c",ch); state = 0;}
            else if (ch=='\\') {printf("%c",ch); state = 6;}
            else printf("%c",ch);
        }
        else if (state==6)
        {
            printf("%c",ch); state = 5;
        }
        else if (state==7)
        {
            if (ch=='\'') {printf("%c",ch); state = 0;}
            else if (ch=='\\') {printf("%c",ch); state = 8;}
            else printf("%c",ch);
        }
        else if (state==8)
        {
            printf("%c",ch); state = 7;
        }
    }
}
