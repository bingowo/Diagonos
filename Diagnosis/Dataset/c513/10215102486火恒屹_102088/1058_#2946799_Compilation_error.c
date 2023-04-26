#include <iostream>
#include <fstream>


using namespace std;

int main()
{
    char c;
    int strflag=0;
    int delflag=0;
    int i=0; //停止输入计数器
    while((c=getchar())&&(i<=10))
    {
        if(c==10)
            i++;
        else i=0;
        if(((c!='/')&&(c!='"')&&(delflag==0))||(strflag==1))   //正常的代码或是在字符串中
            cout<<c;
        else if((strflag==0)&&(delflag==0)&&(c=='/')) //注释的开始
        {
            char d=getchar();
            if(d=='/')
                delflag=1;
            else if(d=='*')
                delflag=2;
            else
                cout<<c<<d;
        }
        else if((strflag==0)&&(delflag==1)&&(c==10)) //行注释的结束
        {
            delflag=0;
            cout<<char(10);
        }
        else if((strflag==0)&&(delflag==2)&&(c=='*')) //段注释的结束
        {
            char d=getchar();
            if(d=='/')
                delflag=0;
            else
                cout<<c<<d;
        }
        else if((delflag==0)&&(c='"')&&(strflag==0)) //字符串的开始
        {
            strflag=1;
            cout<<c;
        }
        else if((delflag==0)&&(c='"')&&(strflag==1)) //字符串的结束
        {
            strflag=0;
            cout<<c;
        }
    }
    return 0;
}
