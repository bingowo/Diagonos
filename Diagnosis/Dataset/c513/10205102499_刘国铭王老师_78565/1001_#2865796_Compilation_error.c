#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    int N,R,r,flag;
    for(int i=0;i<T;i++)
    {
        cin >> N >> R;
        char s[10000];
        if(N<0)
        {
            flag=-1;
            N=-N;
        }
        while(N)
        {
            r=N%R;
            N=N/R;
            if(r>=0&&r<=9)
                s[i++]=r+'0';
            else
                s[i++]=r-10+'A';
        }
        if(flag==-1)
            cout << "-";
        i=i-1;
        while(i>=0)
            cout << s[i--];
            cout<<endl;
    }
    return 0;
}
