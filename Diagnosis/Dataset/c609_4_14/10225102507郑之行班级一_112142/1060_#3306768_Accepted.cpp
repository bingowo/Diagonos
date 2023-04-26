#include <string>
#include <iostream>

using namespace std;

void trans(string in,string ou,int l)
{
    int flag[201]={0};

    for (string::iterator i = in.begin(); i!=in.end(); i++){
        if(*(i+1)>*i)flag[i-in.begin()]=1;
        else if(*(i+1)<*i)flag[i-in.begin()]=-1;
        else flag[i-in.begin()]=0;
    }

    for (string::iterator ini = in.begin();ini!=in.end();ini++){
        if(flag[ini-in.begin()]!=0){
            if(flag[ini-in.begin()]==-1){
                ou.push_back(*ini);
            }
            else if(flag[ini-in.begin()]==1){
                ou.push_back(*ini);
                ou.push_back(*ini);
            }
        }
        else{
            int j=1;
            ini++;
            while(flag[ini-in.begin()]==0){
                ini++;j++;
            }
            if(flag[ini-in.begin()]==-1){
                for (int j1=j;j1>=0;j1--){
                    ou.push_back(*(ini-j1));
                }

            }
            else if(flag[ini-in.begin()]==1){
                for (int j1=j;j1>=0;j1--){
                    ou.push_back(*(ini-j1));
                    ou.push_back(*(ini-j1));
                }
            }
        }
    }
    cout<<ou<<endl;
}

int main()
{
    string in,ou={};
    cin>>in;
    int l=in.length();
    trans(in,ou,l);
    return 0;
}
