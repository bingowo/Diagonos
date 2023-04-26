#include <stdio.h>
#define ll long long

void calco(char *c, ll *co)
{
    while (*c)
    {
        ll sig = 1, coefficient = 0, power = 0;
        if (*c == '-')
        {
            c++;
            sig = -1;
        }
        else if (*c == '+')
        {
            c++;
        }
        while (*c >= '0' && *c <= '9')
        {
            coefficient *= 10;
            coefficient += (*c) - '0';
            c++;
        }

        if (*c == '\0')
        {
            co[0] = coefficient * sig;
            return;
        }
        else if (*c == 'x')
        {
            if (!coefficient)
            {
                coefficient = 1;
            }
            c++;
            if (*c == '^')
            {
                c++;
                while (*c >= '0' && *c <= '9')
                {
                    power *= 10;
                    power += (*c) - '0';
                    c++;
                }
            }
            else
                power = 1;

            co[power] = coefficient * sig;
        }
    }
}

void multiply(char *c1, char *c2, ll *arr)
{
    ll co1[1000] = {0};
    ll co2[1000] = {0};
    calco(c1, co1);
    calco(c2, co2);

    for (ll i = 0; i < 500; i++)
    {
        for (ll j = 0; j < 500; j++)
        {
            arr[i + j] += co1[i] * co2[j];
        }
    }
}

int main()
{
    char s1[1000] = {0}, s2[1000] = {0};
    while ((scanf("%s %s", s1, s2)) == 2)
    {
        ll coefficient[1000] = {0};
        ll out[1000] = {0};
        multiply(s1, s2, coefficient);
        ll sig = 0;
        for (ll i = 0; i < 1000; i++)
        {
            if (coefficient[i])
                out[sig++] = coefficient[i];
        }

        for (ll i = sig - 1; i >= 0; i--)
            printf("%lld ", out[i]);
        printf("\n");
    }
}