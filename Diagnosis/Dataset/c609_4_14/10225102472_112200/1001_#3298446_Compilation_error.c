#if 1
#include<bits/stdc++.h>

using namespace std;
#include<bits/stdc++.h> 
using namespace std;
typedef map<string, vector<int>> mymap; 
typedef vector<int> vi;
typedef vector<string> vs;

mymap countWords(istream& txt, vs& keys){ 
    mymap words;
    string s1, line;
    for(auto &i: keys){ //遍历
        words.insert(pair<string, vi>(i, vi())); //将键值存入words中，并附带空vector
    }
    int count=1;//记录行数
    while(getline(txt, line)){ //从输入流中读取一行文本到line中
        istringstream is(line);//将line转换成输入流对象is
        while(is>>s1){
            for(auto &i: words){ //遍历
                if(i.first==s1){ //若找到对应单词
                    i.second.push_back(count); //将该单词出现的行数存入对应vector中
                    break;
                }
            }
        }
        count++; //更新行数计数器
    }
    return words;
}

void printWords(mymap& keywords){
    ofstream ofs;
    ofs.open("result.txt", ios::out); //打开result.txt文件，并设置输出模式为覆盖写入模式
    for(auto &i: keywords){ //遍历
        ofs<<i.first<<" : { "; //输出单词和冒号，并留出空格
        for(auto &j: i.second){ //遍历该单词对应的行数vector中的每个元素
            ofs<<j<<','; //输出该行数和逗号，并留出空格
        }
        ofs<<" }"<<endl; //输出右花括号和换行符
    }
    ofs.close();
}

int main(){
    ifstream ifs1, ifs2; 
    ifs1.open("Keywords.txt", ios::in); //打开Keywords.txt文件，并设置输入模式为文本模式（默认）
    ifs2.open("Text2search.txt", ios::in); //打开Text2search.txt文件，并设置输入模式为文本模式（默认）
    vs keys;
    string str;
    while(getline(ifs1, str)) keys.push_back(str); //从ifs1中读取一行文本到str中，并将str存入keys中，直到读取完毕
    ifs1.close();
    mymap keywords = countWords(ifs2, keys);
    printWords(keywords);
    ifs2.close();
    return 0;
}
#endif
