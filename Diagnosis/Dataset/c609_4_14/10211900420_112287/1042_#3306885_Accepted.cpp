#include<string>
#include<iostream>
#include<sstream>

using namespace std;

int main()
{
    string s,t,st;
    int T,m,M,x1,x2;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        st.clear();
        m=0;
        cin>>M;
        cin.get();
        getline(cin,s);
        istringstream sin(s);
        cout<<"case #"<<i<<":"<<endl;
        while(sin>>t)
        {
             if(st.size()+t.size()<M)
             {
                 st=st+t;
                 st=st+' ';
             }
             else if(st.size()+t.size()==M)
             {
                 st=st+t;
             }
             else
             {
                 if(st[st.size()-1]==' ')
                 {
                     st.pop_back();
                 }
                 if(st.size()==M)
                 {
                    cout<<st<<endl;
                    st.clear();
                    st=st+t;
                    st=st+' ';
                 }
                 else
                 {
                     x1=M-st.size();
                     while(x1!=0)
                     {
                         for(int j=st.size()-1;j>=0;j--)
                         {
                             if(st[j]==' ')
                             {
                                 st.insert(j,1,' ');
                                 x1--;

                                 while(st[j]==' ')
                                 {
                                     j--;
                                 }

                             }
                             if(x1==0)
                                break;
                         }
                     }
                     cout<<st<<endl;
                     st.clear();
                     st=st+t;
                     st=st+' ';
                 }
            }
        }
        cout<<st<<endl;
    }
    return 0;
}