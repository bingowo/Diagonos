#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char mid;
int flag=0;
int how=1;
int l;
int main()
{
    int m;
    scanf("%d\n",&m);
    for(int z=0;z<m;z++)
    {
        char start;
        scanf("%c",&start);
        switch(start)
        {
        case '(':flag=1;break;
        case '[':flag=2;break;
        case '{':flag=3;break;
        }

        judgea();

        if(how==1) printf("YES");
            else printf("NO");
        printf("\n");
        how=1;
    }
    return 0;
}


int flagb(char c)
{
    switch(c)
        {
        case ')': flag=1;break;
        case ']': flag=2;break;
        case '}': flag=3;break;
        }
    return flag;
}

int flaga(char c)
{
    switch(c)
        {
        case '(': flag=1;break;
        case '[': flag=2;break;
        case '{': flag=3;break;
        }
    return flag;
}

void judgea()
{
    int flagb(char c);
    char c;
    if(scanf("%c",&c)==1)
    {
        switch(c){
    case '(': if(flag==2)
                {
                    flag=1;
                    judgea();
                    break;
                }
                else {how=0;break;}
    case '[':if(flag==3)
                {
                    flag=2;
                    judgea();
                    break;
                }
                else {how=0;break;}
    case '{':if(flag==1)
                {
                    flag=3;
                    judgea();
                    break;
                }
                else {how=0;break;}

    default:{flag=flagb(c);judgeb();break;}
    }
    }

    return;
}

void judgeb()
{
    int flaga(char c);
    char c;
    if(scanf("%c",&c)==1&&c!='\n')
    {
        switch(c){
    case ')':if(flag==3)
                {
                    flag=1;
                    judgeb();
                    break;
                }
                else {how=0;break;}
    case ']':if(flag==1)
                {
                    flag=2;
                    judgeb();
                    break;
                }
                else {how=0;break;}
    case '}':if(flag==2)
                {
                    flag=3;
                    judgeb();
                    break;
                }
                else {how=0;break;}
    default:{flag=flaga(c);judgea();break;}
    }
}
 return;
}
