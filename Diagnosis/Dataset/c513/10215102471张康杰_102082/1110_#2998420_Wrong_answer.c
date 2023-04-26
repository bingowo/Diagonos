#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char input[81],state = 's',state1 = 'd',state2 = 'l';
    char unknown;
    scanf("%s",input);
    int len = strlen(input),i;
    int a = 0,b = 0;
    int l = 0,r = 0;
    //flag表示在等号左边还是右边
    for(i = 0;i < len;i++)
    {
        switch(input[i])
        {
            case '=':
                if(state == 'p')
                    r += b;
                else if(state == 'n')
                {
                    b = -b;
                    r += b;
                }
                a = 0;
                b = 0;
                state = 's';
                state1 = 'd';
                state2 = 'r';
                break;
            case '-':
                if(state != 'u' && state != 's')
                {
                    if(state == 'n')
                        b = -b;
                    if(state2 == 'l')
                        r -= b;
                    else
                        r += b;
                }
                a = 0;
                b = 0;
                state = 'n';
                state1 = 'd';
                break;
            case '+':
                if(state != 'u' || state != 's')
                {
                    if(state == 'n')
                        b = -b;
                    if(state2 == 'l')
                        r -= b;
                    else
                        r += b;
                }
                a = 0;
                b = 0;
                state = 'p';
                state1 = 'd';
                break;
            default:
                if(isalpha(input[i]))
                {
                    unknown = input[i];
                    if(state2 == 'l')
                    {
                        if(state1 == 'g')
                        {
                            if(state == 'n')
                            {
                                a = -a;
                                l += a;
                            }
                            else if(state == 'p' || state == 's')
                            {
                                l += a;
                            }
                        }
                        else if(state1 == 'd')
                        {
                            if(state == 'n')
                            {
                                l += -1;
                            }
                            else if(state == 'p' || state == 's')
                            {
                                l += 1;
                            }
                        }
                    }
                    else if(state2 == 'r')
                    {
                        if(state1 == 'g')
                        {
                            if(state == 'n')
                            {
                                a = -a;
                                l -= a;
                            }
                            else if(state == 'p' || state == 's')
                            {
                                l -= a;
                            }
                        }
                        else if(state1 == 'd')
                        {
                            if(state == 'n')
                            {
                                l -= -1;
                            }
                            else if(state == 'p' || state == 's')
                            {
                                l -= 1;
                            }
                        }
                    }
                    a = 0;
                    b = 0;
                    state = 'u';
                }
                else if(isdigit(input[i]))
                {
                    state1 = 'g';
                    a = a * 10 + input[i] - '0';
                    b = b * 10 + input[i] - '0';
                }
        }
    }
    if(state == 'n')
    {
        b = -b;
        r += b;
    }
    else
        r += b;
    printf("%c=%.3lf\n",unknown,(double)r/(double)l);
    return 0;
}