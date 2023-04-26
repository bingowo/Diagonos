#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int i,len;
    char input[81];
    char state = 's',state1 = 'r',state2 = 'd';
    char unknown;
    int a = 0,b = 0,pow = 1;
    int temp1 = 0,temp2 = 0;
    scanf("%s",input);
    len = strlen(input);
    for(i = len - 1;i >= 0;i--)
    {
        switch(input[i])
        {
            case '=':
                if(state != 'u')
                    b += temp2;
                temp2 = 0;
                pow = 1;
                state1 = 'l';
                break;
            case '+':
                if(state1 == 'r')
                {
                    if(state != 'u')
                    {
                        b += temp2;
                        temp2 = 0;
                        pow = 1;
                    }
                    else
                    {
                        if(state2 == 'd')
                        {
                            temp1 = 1;
                            a -= temp1;
                            temp1 = 0;
                            pow = 1;
                        }
                        else
                        {
                            a -= temp1;
                            temp1 = 0;
                            pow = 1;
                        }
                    }
                }
                else if(state1 == 'l')
                {
                    if(state != 'u')
                    {
                        b -= temp2;
                        temp2 = 0;
                        pow = 1;
                    }
                    else
                    {
                        if(state2 == 'd')
                        {
                            temp1 = 1;
                            a += temp1;
                            temp1 = 0;
                            pow = 1;
                        }
                        else
                        {
                            a += temp1;
                            temp1 = 0;
                            pow = 1;
                        }
                    }
                }
                state2 = 'd';
                state = 'p';
                break;
            case '-':
                if(state1 == 'r')
                {
                    if(state != 'u')
                    {
                        b -= temp2;
                        temp2 = 0;
                        pow = 1;
                    }
                    else
                    {
                        if(state2 == 'd')
                        {
                            temp1 = 1;
                            a += temp1;
                            temp1 = 0;
                            pow = 1;
                        }
                        else
                        {
                            a += temp1;
                            temp1 = 0;
                            pow = 1;
                        }
                    }
                }
                else if(state1 == 'l')
                {
                    if(state != 'u')
                    {
                        b += temp2;
                        temp2 = 0;
                        pow = 1;
                    }
                    else
                    {
                        if(state2 == 'd')
                        {
                            temp1 = 1;
                            a -= temp1;
                            temp1 = 0;
                            pow = 1;
                        }
                        else
                        {
                            a -= temp1;
                            temp1 = 0;
                            pow = 1;
                        }
                    }
                }
                state2 = 'd';
                state = 'n';
                break;
            default:
                if(isalpha(input[i]))
                {
                    unknown = input[i];
                    state = 'u';
                }
                else if(isdigit(input[i]))
                {
                    state2 = 'g';
                    if(state != 'u')
                    {
                        temp2 = temp2 + (input[i] - '0') * pow;
                        pow *= 10;
                    }
                    else
                    {
                        temp1 = temp1 + (input[i] - '0') * pow;
                        pow *= 10;
                    }
                }
        }
    }
    printf("%c=%.3lf\n",unknown,(double)b/(double)a);
    return 0;
}