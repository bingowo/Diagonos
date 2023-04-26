#include <iostream>
#include <stdio.h>
using namespace std;
long long dp[75];
long long IT(int num)
{
    if(num == 0)
    {   return 0; }
    if(num == 1 || num == 2)
    {   return 1; }
    if(dp[num]) //如果之前计算过直接返回
    {   return dp[num]; }
    dp[num] = IT(num - 1) + IT(num - 2)+ IT(num - 3);
    return dp[num];
}
int main()
{
    int t,n;
    unsigned int sum;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        sum=0;
        cin>>n;


        printf("case #%d:\n",i);
        cout << IT(n) <<endl;
    }
    return 0;
}
