#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef long long int LLD;

typedef struct 
{
    LLD re,im;
}COMPLEX;


void Strprocess(COMPLEX*S,char b[]);

COMPLEX Div(COMPLEX S);

int main()
{
    char input[50] = {'0'};
    int bi[1000],cnt = 0,remain;
    scanf("%s",input + 1);
    COMPLEX outcome = {0,0};
    Strprocess(&outcome,input);
    while(outcome.im != 0 && outcome.re != 0)
    {
        if(outcome.re % 2 == 0 && outcome.im % 2 == 0)
            remain = 0;
        else if(outcome.re % 2 == 1 && outcome.im % 2 == 1)
            remain = 0;
        else
            remain = 1;
        bi[cnt++] = remain;
        outcome.re -= 1;
        outcome = Div(outcome);    
    }
    for(int i = cnt - 1;i >= 0;i--)
        printf("%d",bi[i]);
    putchar('\n');
    return 0;
}

void Strprocess(COMPLEX*S,char b[])
{
    int len = strlen(b),i;
    char state = 's',digit = 'n';
    LLD base = 1;
    for(i = len - 1;i >= 0;i--)
    {
        switch(b[i])
        {
            case '-':
            if(state == 'i')
            {
                if(digit == 'y')
                    S->im = -S->im;
                else
                    S->im = -1;
            }
            else
                S->re = -S->re;
            base = 1;
            state = 'n';
            break;
            case '+':
            if(state == 'i')
            {
                if(digit == 'y')
                    S->im = S->im;
                else
                    S->im = 1;
            }
            base = 1;
            state = 'p';
            break;
            case 'i':
            state = 'i';
            break;
            default:
                digit = 'y';
                if(state == 'i')
                {
                    S->im = S->im + base * (b[i] - '0');
                    base *= 10;
                }
                else
                {
                    S->re = S->re + base *(b[i] - '0');
                    base *= 10;
                }
        }
    }
    return;
}

COMPLEX Div(COMPLEX S)
{
    COMPLEX R = {0,0};
    LLD temp_re,temp_im;
    temp_re = S.im - S.re;
    temp_im = -(S.im + S.re);
    R.im = temp_im;
    R.re = temp_re;
    return R;
}