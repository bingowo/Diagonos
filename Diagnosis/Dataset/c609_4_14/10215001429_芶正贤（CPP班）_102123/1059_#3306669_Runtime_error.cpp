#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct CASE
{
    int flag;
    int fir;
    string sec;
    int pos;
};

bool cmp(CASE X,CASE Y)
{
    if(X.flag!=Y.flag)
        return (X.flag<Y.flag);
    else//符号位相同
    {
        if(X.flag>0)//均为非负值
        {
            if(X.fir!=Y.fir)
                return (X.fir<Y.fir);
            else
            {
                if(X.sec!=Y.sec)
                    return (X.sec<Y.sec);
                else
                    return true;
            }
        }

        if(X.flag<0)//均为负值
        {
            if(X.fir!=Y.fir)
                return (X.fir>Y.fir);
            else
            {
                if(X.sec!=Y.sec)
                    return (X.sec>Y.sec);
                else
                    return true;
            }
        }
    }
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
        if(temp[0]=='-')//负数
        {
            Num[i].flag=-1;
            Num[i].fir=0;
            for(int h=0;h<100;h++)
            {
                Num[i].sec[h]=0;
            }
            
            Num[i].pos=i;
            mark=1;
        }
        else//非负数
        {
            Num[i].flag=1;
            Num[i].fir=0;
            for(int h=0;h<100;h++)
            {
                Num[i].sec[h]=0;
            }
            Num[i].pos=i;
            if(temp[0]=='+')
                mark=1;
        }
        int j;
        for(j=mark;j<temp.length();j++)//读入整数部分
        {
            if(temp[j]=='.')
            {
                break;//break时为小数点位
            }
            Num[i].fir+=temp[j]-'0';
            Num[i].fir=Num[i].fir*10;
        }
        if(Num[i].fir!=0)
        {
            Num[i].fir=Num[i].fir/10;
        }

        if(j==temp.length())//无小数部分
        {
            
        }
        else
        {
            j++;//跳过小数点位
            int r=0;
            for(;j<temp.length();j++)
            {
                Num[i].sec[r]=temp[j];
                r++;
            }
        }
    }
    sort(Num,Num+n,cmp);
    for(int i=0;i<n;i++)
    {
        cout<<ori[Num[i].pos]<<endl;
    }
}