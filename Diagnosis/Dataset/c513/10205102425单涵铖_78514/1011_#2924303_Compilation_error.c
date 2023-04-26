#include<iostream>
#include<stack>
using namespace std;

string alpha = "0123456789ABCDEF";

void transI(stack<int>&bin)
{
    long long i = 0;
    long long r = 0;
    int len = bin.size();
    
    for(int j = len; j > 1; j--)
    {
        //这时候你从stack取出来的是最高位
        //比如说二进制111，两位，那么只需要处理前两位
        int temp = bin.top();
        
        if(temp == 0)
        {
            bin.pop();
            continue;
        }

        if( j != 0 )
        {
            long long a = -1;
            long long b = 1;
            int c = -1;
            int d = 1;
            
            for(int k = j - 2; k > 0; k--)//两个-1+i相乘本身就有两次了，所以对应的j要多-1而且k要>0
            {
                long long ta = a;
                long long tb = b;
                a = (ta * c - tb *d);
                b = (tb * c + ta *d);
            }
            //cout << "a "<<a<<" b "<<b<<endl;
            
            
            bin.pop();
            i += b;
            r += a;
            
        }
        
        
    }
    int temp = bin.top();
    r += temp;
    
    int puti = 0;
    int putr = 0;
    int positive = 0;
    int one = 0;
    if(i)
    {
        puti = 1;
        if(i == 1 || i == -1){one = 1;}
        if(i > 0){positive = 1;}
    }
    if(r){putr = 1;}
    

    if(putr)
    {cout << r;}
    if(positive && putr)
    {cout << '+';}
    
    if(puti && !one)
    {cout<< i << "i" ;}
    else if(puti && one)
    {
        cout << ((i > 0)?"i":"-i");
        
    }
}

int main()
{
    string hexadecimal;
    cin >> hexadecimal;

    if(hexadecimal == "0x0")
    {
        cout << "0";
        return 0;
    }
    int len = hexadecimal.length();
    long long decimal = 0;
    for(int i = 2; i < len; i++)
    {
        decimal *= 16;
        decimal += alpha.find(hexadecimal[i]);

        
    }
    
    stack<int>bin;
    while(decimal)
    {
        int temp = decimal % 2;
        bin.push(temp);
        decimal >>= 1;
        
    }
    //写-1+i次方的算法计算出每次计算后对应的 r 和 l 所加的大小
    
    //cout << bin.size()<<endl;
    transI(bin);

    return 0;
}
