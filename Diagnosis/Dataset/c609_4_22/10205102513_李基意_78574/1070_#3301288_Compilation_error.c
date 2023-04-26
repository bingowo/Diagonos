#include <iostream>
using namespace std;
int main()
{
    int m, n[21]={0};
    n[1]=2;
    n[2]=4;
    n[3]=7;
    for(int i=4; i<21; i++) n[i]=2*n[i-1]-n[i-2]+n[i-3];
    cin>>m;
    while(m+1){cout<<n[m]<<endl;cin>>m;}
    return 0;
}