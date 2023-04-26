#include<iostream>
#include<cmath>

using namespace std;
const int N=1e6;
long long f[N];
bool p[1020];


bool primer(int n)/*先判断是否是素数*/
{
    for(int i = 2;i <= sqrt(n);i++)
    {
        if(n % i == 0)
        {
            return 0;
        }
        return 1;
    }
}

int main()
{
    int n;
    cin>>n;
    f[0]=1;
    for(int i = 3;i <= 1000;i++)
    {
        if(primer(i))
        {
            p[i]=1;
        }
    }
    p[2]=1;
    for(int i = 2;i <= n;i++)
    {
        if(p[i])
        {
            for(int j = i;j <= n;j++)
            {
                f[j]+=f[j-i];
            }
        }
    }
    cout<<f[n];
    return 0;
}
