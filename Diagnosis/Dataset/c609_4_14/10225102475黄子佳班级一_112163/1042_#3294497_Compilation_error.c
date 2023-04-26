#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    int T;
    cin>>T;
    string str;
    string s;
    string words[10001];
    int M;

    for(int i{};i<T;i++)
        {
            cin>>M;
            cin.ignore();
            getline(cin,str);
            istringstream sin(str);//使istringstream类型对象与字符串str绑定
            int index{};
            while(sin>>words[index])index++;//用string数组来储存单词

            cout<<"case #"<<i<<":"<<endl;
            int sum=index;//总个数
            index=0;

            while(index<sum)
            {
                int len{};
                int cnt=1;
                len=words[index].length();
                while((len+cnt-1<M)&&index<sum-1)
                {
                    index++;
                    cnt++;
                    len=len+words[index].length();
                }
                if(index==sum-1)//最后一行
                {
                      for(int k=index-cnt+1;k<sum;k++)
                     {
                         cout<<words[k];
                         if(k!=index)cout<<" ";
                      }
                       cout<<endl;
                }
                else if(len+cnt-1==M)//正好每个单词用一个空格分隔
                {
                    for(int k=index-cnt+1;k<index+1;k++)
                    {
                        cout<<words[k];
                        if(k!=index)cout<<" ";
                    }
                    cout<<endl;
                }
                else//去掉最后一个单词
                {
                    len=len-words[index].length();
                    index--;
                    cnt--;
                    int space=M-len;//需要的空格数量
                    cnt--;
                    int mini=space/cnt;//每次最小空格数
                    int surp=space%cnt;//多余的
                    cnt++;

                    string tmp[10001];//存放空格
                    for(int k=0;k<cnt-1;k++)
                    {
                        tmp[k]=" ";
                        for(int m=1;m<mini;m++)
                        {
                            tmp[k]+=" ";
                        }
                        if(k>=cnt-1-surp)tmp[k]+=" ";
                    }
                    int m=0;
                    for(int k=index-cnt+1;k<index+1;k++)
                    {
                        cout<<words[k];
                        cout<<tmp[m++];
                    }
                    cout<<endl;
                }
                index++;
            }
        }
        return 0;
}
