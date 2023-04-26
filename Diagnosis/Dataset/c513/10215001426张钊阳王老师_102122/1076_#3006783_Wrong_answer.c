#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char mid;
int flag=0;
int how=1;
int l;
int i;
char s[200];
int main()
{
    int m;
    scanf("%d\n",&m);
    for(int z=0;z<m;z++)
    {
        memset(s,'\0',200);
        char start;
        scanf("%s",s);
        start=s[0];
        i++;
        switch(start)
        {
        case '(':flag=1;break;
        case '[':flag=2;break;
        case '{':flag=3;break;
        }

        judgea();

        if(how==1) printf("Yes");
            else printf("No");

        printf("\n");
        how=1;
        i=0;
    }
    return 0;
}


int flagb(char c)
{
    int flag0;
    switch(c)
        {
        case ')': flag0=1;break;
        case ']': flag0=2;break;
        case '}': flag0=3;break;
        }
    return flag0;
}

int flaga(char c)
{
    int flag0;
    switch(c)
        {
        case '(': flag0=1;break;
        case '[': flag0=2;break;
        case '{': flag0=3;break;
        }
    return flag0;
}

void judgea()
{
    int flagb(char c);
    char c;
    if(s[i]!='\0')
    {
        switch(s[i]){
    case '(': if(flag==2)
                {
                    flag=1;
                    i++;

                    judgea();
                    break;
                }
                else {how=0;break;}
    case '[':if(flag==3)
                {
                    flag=2;
                    i++;

                    judgea();
                    break;
                }
                else {how=0;break;}
    case '{':if(flag==1)
                {
                    flag=3;
                    i++;

                    judgea();
                    break;
                }
                else {how=0;break;}

    default:{
    if(flaga(s[i-1])!=flagb(s[i])){how=0;break;}
     {flag=flagb(s[i]);i++;judgeb();break;}
    }

    }
    }

    return;
}

void judgeb()
{
    int flaga(char c);
    char c;
    if(s[i]!='\0')
    {
        switch(s[i]){
    case ')':if(flag==3)
                {
                    flag=1;
                    i++;
                    judgeb();
                    break;
                }
                else {how=0;break;}
    case ']':if(flag==1)
                {
                    flag=2;
                    i++;
                    judgeb();
                    break;
                }
                else {how=0;break;}
    case '}':if(flag==2)
                {
                    flag=3;
                    i++;
                    judgeb();
                    break;
                }
                else {how=0;break;}
    default:{
        flag=flaga(s[i]);i++;judgea();break;}
    }
}
 return;
}
