#include<stdio.h>
int main()  
{  
    char c;  
    int flag = 0;  
    while((c = getchar()) != EOF)  
    {  
        switch(flag)  
        {  
        case 0:
            if(c == '/')
                flag = 1;
            else if(c == '\'')
                flag = 6;
            else if(c == '\"')
                flag = 8;
            else
                putchar(c);
            break;
        case 1:
            if(c == '*')
                flag = 2;
            else if(c == '/')
                flag = 4;
            else{
                putchar('/');
                putchar(c);
                flag = 0;
            }
            break;
        case 2:
            if(c == '*')
                flag = 3;
            else
                flag = 2;
            break;  
        case 3:
            if(c == '/')
                flag = 0;
            else if(c == '*')
                flag = 3;
            else
                flag = 2;
            break;  
        case 4:
            if(c == '\\')
                flag = 5;
            else if(c == '\n'){  
                flag = 0;
                putchar(c);
            }
            break;
        case 5:
            if(c == '\\')
                flag = 5;
            else
                flag = 4;
            break;
        case 6:
            if(c == '\\')
                flag = 7;
            else if(c == '\''){
                flag = 0;
                putchar(c);
            }
            break;
        case 7:
            flag = 6;
            break;
        case 8:
            if(c == '\\')
                flag = 9;
            else if(c == '\"'){
                flag = 0;
                putchar(c);
            }
            break;
        case 9:
            flag = 8;
            break;
        }
        if(flag == 6 || flag == 7 || flag == 8 || flag == 9)
            putchar(c);
    }
    return 0;
} 