#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
    int T,M,cnt,sum,num;
    //sum记录当前所有单词和一个空格所需要的空间
    //num记录所需要空格数
    //cnt记录当前单词个数
    cin >> T;
    for (int I = 0; I < T; I++)
    {
        cout << "case #" << I << ":" << endl;
        cin >> M;
        cin.ignore();//吃掉空格
        vector <string> str;
        string t,s;
        getline(cin,t);
        istringstream sin(t);
        cnt = 0; sum = 0;//重置
        while (sin >> s)
        {
            if (s.size() > (M - sum))//当下一个字符超过剩余空间时，输出这一行
            {
                for (int i = 0; i < cnt-1; i++)
                {
                    cout << str[i];
                    //计算空格数
                    num = (M - sum) / (cnt - 1);
                    if (i >= (cnt - 2) - (M - sum) % (cnt - 1)) num++;
                    //输出空格
                    for (int j = 0; j < num + 1; j++) cout << ' ';
                }
                cout << str[cnt-1] << endl;
                sum = 0; cnt = 0; str.clear();//重置
            }
            sum = sum + s.size() + 1; cnt++;
            str.push_back(s);
        }
        for (int i = 0; i < cnt-1; i++) cout << str[i] << ' ';
        cout << str[cnt-1] << endl;
    }
    return 0;
}