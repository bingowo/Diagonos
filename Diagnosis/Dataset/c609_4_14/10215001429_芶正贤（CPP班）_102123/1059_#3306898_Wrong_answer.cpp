#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct CASE
{
    int flag;
    double num;
    int pos;
};

bool cmp(CASE X,CASE Y)
{
    if(X.flag!=Y.flag)
    {
        return X.flag<Y.flag;
    }
    else if(X.flag>0)
        return X.num<Y.num;
    else
        return X.num>Y.num;

}

int main()
{
    int n;
    cin>>n;
    CASE Num[n];
    vector<string> ori;
    for(int i=0;i<n;i++)
    {
        string temp;
        cin>>temp;
        ori.push_back(temp);
        int mark=0;
        if(temp[0]=='-')
        {
            Num[i].flag=-1;
            mark=1;
            Num[i].pos=i;
        }
        else
        {
            Num[i].flag=0;
            if(temp[0]=='+')
                mark=1;
            Num[i].pos=i;
        }
            
        Num[i].num = stod(temp.substr(mark,temp.length()-mark));
    }
    sort(Num,Num+n,cmp);
    for(int i=0;i<n;i++)
    {
        cout<<ori[Num[i].pos]<<endl;
    }
}