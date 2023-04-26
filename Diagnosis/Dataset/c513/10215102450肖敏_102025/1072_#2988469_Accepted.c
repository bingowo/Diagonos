#include <stdio.h>
#define ll long long

int times = 0;
char STR[100001];
void direction(ll x, ll y)
{
    if(x % 2 != 0)
    {
        ll E = x - 1;
        ll W = x + 1;
        //搞清楚怎么走是向东走。
        E /= 2;
        W /= 2;
        y /= 2;
        if(y == 0 && E == 0)
        {
            STR[times] = 'E';
            times++;
            return;//
        }
        if(y == 0 && W == 0)
        {
            STR[times] = 'W';
            times++;
            return;
        }

        if((E + y) % 2 != 0)
        {
            STR[times] = 'E';
            times++;
            direction(E,y);
        }
        else if((W + y) % 2 != 0)
        {
            STR[times] = 'W';
            times++;
            direction(W,y);
        }

    }
    else if (y % 2 != 0)
    {

        ll N = y - 1;
        ll S = y + 1;
        //同上
        S /= 2;
        N /= 2;
        x /= 2;
        if(x == 0 && N == 0)
        {
            STR[times] = 'N';
            times++;
            return;
        }
        if(x == 0 && S == 0)
        {
            STR[times] = 'S';
            times++;
            return;
        }

        if((x + S) % 2 != 0)
        {
            STR[times] = 'S';
            times++;
            direction(x,S);
        }
        else if((x + N) % 2 != 0)
        {
            STR[times] = 'N';
            times++;
            direction(x,N);
        }
    }

}

int main()
{
    ll x,y;
    scanf("%lld%lld",&x,&y);
    if(x == 0 && y == 0)
    {
        printf("0\n");
    }
    else if((x + y) % 2 == 0)
    {
        printf("-1\n");
        return 0;
    }

    else
    {
        direction(x,y);
        printf("%d\n",times);
        for(int i=0;i<times;i++)
        {
            printf("%c",STR[i]);
        }
        printf("\n");
    }
    return 0;
}
