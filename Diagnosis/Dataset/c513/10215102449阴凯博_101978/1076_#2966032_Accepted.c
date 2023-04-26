#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void push(char* s,char a)
{
    s[strlen(s)]=a;
}

void pop(char* s)
{
    s[strlen(s)-1]='\0';
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        char str[120]={0},s[120]={0};
        char c;
        int j=0,flag=1;
        scanf("%s",str);
        int len=strlen(str);
        for (j=0;j<len;j++)
        {
            if (strlen(s)==0)
            {
                push(s,str[j]);
                continue;
            }

            switch(str[j])
            {
        case '(':
            if(s[strlen(s)-1] == '[')
            {
                push(s,str[j]);
            }
            else{
                flag = 0;
                goto FLAG;
            }
            break;

        case')':
            if(s[strlen(s)-1] == '(')
            {
                pop(s);
            }
            else{
                flag = 0;
                goto FLAG;
            }
            break;



        case '[':
            if(s[strlen(s)-1]== '{')
            {
                push(s,str[j]);
            }
            else{
                flag = 0;
                goto FLAG;
            }
            break;


        case']':
            if(s[strlen(s)-1] == '[')
            {
                pop(s);
            }
            else{
                flag = 0;
                goto FLAG;
            }
            break;





        case '{':
            if(s[strlen(s)-1] == '(')
            {
                push(s,str[j]);
            }
            else{
                flag = 0;
                goto FLAG;
            }
            break;


        case'}':
            if(s[strlen(s)-1] == '{')
            {
                pop(s);
            }
            else{
                flag = 0;
                goto FLAG;
            }
            break;
        }
    }
         FLAG:
        if(flag && strlen(s)==0 ) printf( "Yes\n");
        else printf("No\n");
    }
    return 0;
}
