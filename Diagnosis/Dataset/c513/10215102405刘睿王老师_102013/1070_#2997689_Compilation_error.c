#include<iostream>
using namespace std;



int main()
{
    long long arr[21];
    arr[0] = 0;
    arr[1] = 2;
    arr[2] = 4;
    arr[3] = 7;
    for(int i = 4; i < 21; i++)
    {
        arr[i] = arr[i - 1] * 2 - arr[i - 2] + arr[i - 3];
    }
    
    int n;
    while((cin >> n)&& n != -1)
    {
        cout << arr[n]<<endl;
    }
    return 0;
}
