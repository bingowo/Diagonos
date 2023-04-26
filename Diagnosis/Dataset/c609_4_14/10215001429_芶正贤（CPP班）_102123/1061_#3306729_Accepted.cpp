#include <iostream>
#include <algorithm>
#include<cmath>
using namespace std;

const int N=1e6;
long long f[N];
bool primer[1010];

//判断素数
bool isprimer(int x) 
{
	for (int i = 2; i <= sqrt(x); i++)
        if (0 == x % i)
            return 0;
	return 1;
}
 
int main()
{
	int n;
	cin >> n;
	f[0] = 1;
    
	for (int i = 3; i <= 1000; i++)
        if (isprimer(i))
            primer[i] = 1;
    
	primer[2] = 1;
	for (int i = 2; i <= n; i++)
    {
		if (primer[i])//外层循环枚举所有素数
        {
            for (int j = i; j <= n; j++)//内层循环枚举背包容量j
                //在当前选定的素数i下，将容量为j的背包填满的不同方案数
            {//
                f[j] = f[j] + f[j - i];
                //f[j-i]表示在容量为j-i的背包中填充素数i所能够得到的拆分方式数
            }
        }
            
	}
	cout << f[n];
}