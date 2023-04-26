#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a,string b)
{
    int a_sign=1,b_sign=1;  //判断正负号
    int a_intlen=a.length(),b_intlen=b.length(); //记录整数部分长度

    if(a[0] == '-') a_sign= -1;
    if(b[0] == '-') b_sign= -1;

    //测试程序
    /*cout<<endl;
    cout<<"a:"<<a<<" "<<"a_sign:"<<a_sign<<endl;
    cout<<"b:"<<b<<" "<<"b_sign:"<<b_sign<<endl;*/

    if(a.find('.')!=string::npos){
        a_intlen = a.find('.');
    }
    if(a[0]=='-'||a[0]=='+') a_intlen -= 1;
    //cout<<"a_intlen:"<<a_intlen<<endl;
    if(b.find('.')!=string::npos){
        b_intlen = b.find('.');
    }
    if(b[0]=='-'||b[0]=='+') b_intlen -= 1;
    //cout<<"b_intlen:"<<b_intlen<<endl;

    if(a_sign != b_sign){
        int i = -1;
        if(a_sign>b_sign) i = 1;
        return i; //正负不同直接比正负
    }
    else if(a_intlen != b_intlen){
        return a_sign*(a_intlen-b_intlen); //正负相同，整数长度不同，比整数长度
    }
    return a_sign*a.compare(b); //均相同，比较字符串字典
}

int main()
{
    int n,i;
    string num;
    vector<string> m;
    cin>>n;  //数字个数
    for(i=0;i<n;i++){
        cin>>num;
        m.push_back(num);
    }
    sort(m.begin(),m.end(),cmp);
    cout<<endl;
    //最后的输出
    for(auto e:m){
        cout<<e<<endl;
    }

    return 0;
}
