
#include<stdio.h>
#include<math.h>
using namespace std;
typedef long long ll;
typedef struct{
	ll first;
	ll second;
}pair;
int main()
{
    ll a;
 scanf("%lld",&a);
    ll b = 0;
    while((b+1) * (b+1) <= a)//b2 <= a < (b+1)2
        b++;
    ll c = a - b * b;
    pair p;
    if(b % 2)
    {
        p.first = b / 2;
        p.second = b / 2 + 1;
        if(c > b)
        {
            p.first -= b;
            p.second -= c - b;
        }
        else
        {
            p.first -= c;
        }
    }
    else
    {
        p.first = -b / 2;
        p.second = -b / 2;
        if(c > b)
        {
            p.first += b;
            p.second += c - b;
        }
        else
        {
            p.first += c;
        }
    }
    printf("(%d,%d)",p.first,p.second);

}
