#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int GCD(int x,int y)
{
    int temp,rest;
    if(x < y)
    {
        temp = x;
        x = y;
        y = temp;
    }
    rest = x % y;
    while(rest != 0)
    {
        x = y;
        y = rest;
        rest = x % y;
    }
    return y;
}

int main()
{
    char input[20];
    scanf("%s",input);
    int exp[3],a = 0,b = 0;
    char*pt = input;
    char state = 'e',state1 = 'd';
    while(*pt)
    {
        switch(*pt)
        {
            case '-':
                if(state == 'u')
                {
                    exp[1] = a;
                    a = 0;
                }
                else if(state == 'i')
                {
                    exp[b] = a;
                    b = 0;
                    a = 0;
                }  
                state = 'n';
                pt++;
                break;
            case '+':
                if(state == 'u')
                {
                    exp[1] = a;
                    a = 0;
                }
                else if(state == 'i')
                {
                    exp[b] = a;
                    b = 0;
                    a = 0;
                }  
                state = 'p';
                pt++;
                break;
            case 'x':
                if(state1 == 'g')
                {
                    if(state == 'n')
                        a = -a;
                    state1 = 'd';
                }
                else if(state1 == 'd')
                {
                    if(state == 'n')
                        a = -1;
                    else if(state == 'p')
                        a = 1;
                    else if(state == 'e')
                        a = 1;
                }
                state = 'u';
                pt++;
                break;
            case '^':
                state = 'i';
                pt++;
                break;
            default:
                if(state == 'n')
                {
                    a = a * 10 + (*pt - '0');
                    state1 = 'g';
                }
                else if(state == 'p' || state == 'e')
                {
                    a = a * 10 + (*pt - '0');
                    state1 = 'g';
                }
                else if(state == 'i')
                    b = b * 10 + (*pt - '0');
                pt++;
        }
    }
    if(state == 'u')
        exp[1] = a;
    else if(state == 'i')
    {
        exp[b] = a;
    }
    else if(state == 'n')
        exp[b] = -a;
    else
        exp[b] = a;
    int judge = exp[1] * exp[1] - 4 * exp[2] * exp[0];
    int root,solve1,solve2,m,m1,m2;
    root = sqrt(judge);
    if(judge < 0 || (root * root != judge))
        printf("No Answer!\n");
    else
    {
        solve1 = -exp[1] + root;
        solve2 = -exp[1] - root;
        m = 2 * exp[2];
        m1 = GCD(abs(solve1),abs(m));
        m2 = GCD(abs(solve2),abs(m));
        solve1 /= m1;
        m1 = m / m1;
        solve2 /= m2;
        m2 = m / m2;
        if(m1 < m2)
            printf("%d %d %d %d\n",m1,-solve1,m2,-solve2);
        else if(m1 > m2)
            printf("%d %d %d %d\n",m2,-solve2,m1,-solve1);
        else
        {
            if(-solve1 < -solve2)
                printf("%d %d %d %d\n",m1,-solve1,m2,-solve2);
            else
                printf("%d %d %d %d\n",m2,-solve2,m1,-solve1);
        }
    }
    return 0;
}