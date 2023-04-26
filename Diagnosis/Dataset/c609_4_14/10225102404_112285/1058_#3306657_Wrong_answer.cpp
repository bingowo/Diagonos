#include<iostream>

using namespace std;
int main()
{
    int r,k=0,c[10000];
    long long n;
    cin>>n;
    if(n==0)
    {
        cout<<0<<endl;
        return 0;
    }
    while(n)
    {
        r=n%-2;
        n/=-2;
        if(r>=0)
        {
            c[k++]=r;
        }
        else
        {
            c[k++]=r-(-2);
            n++;
        }
    }
    for(int i=k-1;i>=0;i--)
    {
        cout<<c[i];
    }
    return 0;

}
