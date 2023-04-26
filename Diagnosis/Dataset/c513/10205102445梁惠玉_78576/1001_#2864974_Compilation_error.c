#include <iostream>

using namespace std;

void exchange(int n,int r)
{
    int m;
    if(n)
    {
        exchange(n/r,r);
        m=n%r;
        if(m>=10)
        {
           char c=m+55;
           cout<<c;
        }
        else{
            cout<<m;
        }
    }

}

int main()
{
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int n,r;
        cin>>n>>r;
        if(n<0)
        {
            n=abs(n);
            cout<<"-";
        }
        exchange(n,r);
        cout<<endl;
    }
    return 0;
}