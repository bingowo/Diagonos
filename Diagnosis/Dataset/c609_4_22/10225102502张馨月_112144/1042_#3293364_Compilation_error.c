#include<iostream>
#include <sstream>
using namespace std;

int main()
{
    int T;
    cin>>T;
    for(int z=0;z<T;z++)
    {
        int M;//排版后每行长度
        cin>>M;
        getchar();
        string s;
        getline(cin,s);
        int s_len = s.length();//字符串总长度

        cout<<"case #"<<z<<":"<<endl;

        int i=0;
        while(i<s_len)
        {
            for(;s[i]== ' ';i++);//跳过行首空格

            //统计每行输出的单词总长度,个数
            int start = i;//每行的开头
            int words_len = 0;//每行输出的单词字母数
            int words_count = 0;//每行输出的单词个数 还是最少空格数+1

            for(;words_len+words_count<=M&&i<s_len;)
            {
                int j,p;
                for(j=0,p=i;s[p]!= ' '&&p<s_len;p++,j++);
                if(j + words_len + words_count <= M)
                {
                    words_len +=j;
                    words_count++;
                    for(i=p;s[i]==' ';i++);
                }
                else
                    break;
            }
            int space=M-words_len;
            words_count--;

            //按排版要求输出
            while(start<i)
            {
                while(s[start] != ' ' && start < i)
                    cout << s[start++];
                while(s[start]==' '&&start<i)
                    start++;

                if(i==s_len&&words_count)
                    cout << ' ';
                else
                {
                    int j = 0;
                    for(;words_count&&j<space/words_count;j++)
                        cout << " " ;
                    space=space-j;
                }
                words_count--;
            }
            cout << endl;
        }
    }
    return 0;
}
