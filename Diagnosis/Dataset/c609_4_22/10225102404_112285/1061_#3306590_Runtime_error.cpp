#include<iostream>
#include<cmath>

using namespace std;


int primer(int n)/*先判断是否是素数*/
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
    long long f[10000];
    int p[1001];
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
