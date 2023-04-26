#include <stdio.h>

int times = 0,i=0;
char s[];
void direction(long long x, long long y)
{
    if(x % 2 != 0)
    {
        long long E = x - 1;
        long long W = x + 1;
        E /= 2;
        W /= 2;
        y /= 2;
        if(y == 0 && E == 0)
        {
            times++;
            s[i] = 'E';
            i++;
            return;
        }
        if(y == 0 && W == 0)
        {
            times++;
            s[i] = 'W';
            i++;
            return;
        }

        if((E + y) % 2 != 0)
        {
            times++;
            s[i] = 'E';
            i++;
            direction(E,y);
        }
        else if((W + y) % 2 != 0)
        {
            times++;
            s[i] = 'W';
            i++;
            direction(W,y);
        }

    }
    else if (y % 2 != 0)
    {

        long long N = y - 1;
        long long S = y + 1;
        S /= 2;
        N /= 2;
        x /= 2;
        if(x == 0 && N == 0)
        {
            times++;
            s[i] = 'N';
            i++;
            return;
        }
        if(x == 0 && S == 0)
        {
            times++;
            s[i] = 'S';
            i++;
            return;
        }

        if((x + S) % 2 != 0)
        {
            times++;
            s[i] = 'S';
            i++;
            direction(x,S);
        }
        else if((x + N) % 2 != 0)
        {
            times++;
            s[i] = 'N';
            i++;
            direction(x,N);
        }
    }

}

int main()
{
    long long x,y;
    scanf("%lld %lld",&x,&y);
    if(x == 0 && y == 0)
    {
        printf("0");
    }
    else if((x + y) % 2 == 0)
    {
        printf("-1");
        return 0;
    }

    else
    {
        direction(x,y);
        printf("%d\n",times);
        printf("%s",s);
    }

    return 0;
}
