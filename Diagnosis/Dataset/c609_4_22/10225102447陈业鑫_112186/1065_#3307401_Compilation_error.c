#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

double cal() {
    char str[20];
    cin >> str; 
    //因为输入的时候每个字符用空格隔开的，所以每调用一次输入一次相当于
    switch (str[0])
    {
    case '+':
        return cal() + cal(); break;
    case '-':
        return cal() - cal(); break;
    case '*':
        return cal() * cal(); break;
    case '/':
        return cal() / cal(); break;
    default:
        return atof(str);
    }
}

int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cout << "case #" << i << ":" << endl;
        cout << setiosflags(ios::fixed) << setprecision(6) << cal() << endl;
        //保留精度的方法
    }
    
    return 0;
}