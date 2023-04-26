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
    int land;
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
            else//整数位相等
            {
                if(X.land!=Y.land)
                    return X.land<Y.land;
                else
                {
                    if(X.sec!=Y.sec)
                    {
                        for(int i=0;i<100;i++)
                        {
                            if(X.sec[i]!=Y.sec[i])
                            {
                                return X.sec[i]<Y.sec[i];
                            }
                        }
                    }
                    else
                        return true;
                }
                    
                    
                
            }
        }

        if(X.flag<0)//均为负值
        {
            if(X.fir!=Y.fir)
                return (X.fir>Y.fir);
            else//整数位相等
            {
                if(X.land!=Y.land)
                    return X.land>Y.land;
                else
                {
                    if(X.sec!=Y.sec)
                    {
                        for(int i=0;i<100;i++)
                        {
                            if(X.sec[i]!=Y.sec[i])
                            {
                                return X.sec[i]>Y.sec[i];
                            }
                        }
                    }
                    else
                        return true;
                }
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
            Num[i].pos=i;
            Num[i].sec={};
            mark=1;
        }
        else//非负数
        {
            Num[i].flag=1;
            Num[i].fir=0;
            Num[i].pos=i;
            Num[i].sec={};
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
            Num[i].land=1;
        }
        else
        {
            Num[i].land=0;
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