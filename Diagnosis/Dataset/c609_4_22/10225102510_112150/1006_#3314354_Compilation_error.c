#include<iostream>
#include<map>
#include<string>
#include<math.h>
using namespace std;
int main()
{
    int Q;
    int flag;
    map<string,int> o;
    int x,y,min;
    string A;
    cin>>Q;
    for(int i=0;i<Q;i++)
    {
        cin>>flag;
        if(flag==1){
            cin>>A;
            cin>>x;
            cin>>y;
            o[A]=sqrt(x*x+y*y);
            if(i==1)
            min=o[A];
            min=o[A]<min?o[A]:min;
        }
        if(flag==2){
            cin>>A;
            o.erase(A);
        }
        if(flag==3){
            cout<<A<<endl;
        }
    }
}