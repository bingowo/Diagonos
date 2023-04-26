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
        return a_sign>b_sign; //正负不同直接比正负
    }
    else if(a_intlen != b_intlen){
        int i = a_sign*(a_intlen-b_intlen);
        return i>0; //正负相同，整数长度不同，比整数长度
    }else{
        string A,B;
        A = a;
        B = b;
        if(A[0]=='+'||A[0]=='-') A.erase(0,1);  //删除开头的'+'和'-'
        if(B[0]=='+'||B[0]=='-') B.erase(0,1);
        return a_sign*A.compare(B)>0; //均相同，比较字符串字典
    }
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

    //最后的输出
    cout<<endl;
    cout<<"结果："<<endl;
    vector<string>::iterator j;
    for(j = m.end()-1;j>=m.begin();j--){
        cout<<*j<<endl;
    }

    return 0;
}
