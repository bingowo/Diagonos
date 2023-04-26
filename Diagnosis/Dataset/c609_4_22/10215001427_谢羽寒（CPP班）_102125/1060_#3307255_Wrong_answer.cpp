#include <iostream>
#include <string>

using namespace std;


void dfs(string &str)
{
    long long len = str.size();
    string str2;
    str2=str;//用来保存原字符窜

    // 如果当前字符串长度已经等于1，则无法再进行变换，直接返回
    if (len == 1)
    {
        return;
    }

    // 枚举每个字符，将其变换后放回原字符串中
    long long j = 0;
    long long i;
    for (i = 0; i < len - 1; i ++,j++ )
    {
        // 如果当前字符比后一个字符大，则不进行变换
        if (str2[i] > str2[i + 1]){continue;}

        else if(str2[i] < str2[i + 1]){

            str.insert(j+1, 1, str2[i]);//在str的第j+1个字符前面插入str2[i]
            j++;//多跳一个

        }
        else if(str2[i] == str2[i + 1]){// 如果当前字符等于后一个字符，则继续判断
                long long cnt;
                cnt=i+1;
                int flag=0;//记录重复字符子串和刚结束重复字符子串以后的那个字母，谁大谁小
                while(cnt<len-1){
                    if(str2[cnt] < str2[cnt+1]){ flag=-1;break;}//重复字符子串结束break
                    else if(str2[cnt]>str2[cnt+1]){flag=1;break;}//重复字符较大

                    cnt++;
                    }

                if(flag==0){return;}//重复一直到结束
                else if(flag==1){
                    i=i+cnt-2;
                    j=j+cnt-2;
                }
                else if(flag == -1){
                    cnt++;
                    long long c;
                    c=cnt-i;
                    while(c){
                         str.insert(j+1, 1, str2[i]);//在str的第j+1个字符前面插入str2[i]
                        j++;//多跳一个
                        i++;
                         c--;
                    }
                }
        }

    }
    return;

}

int main()
{
    string s;
    cin >> s;
    getchar();

    dfs(s);

    cout << s << endl;

    return 0;
}
