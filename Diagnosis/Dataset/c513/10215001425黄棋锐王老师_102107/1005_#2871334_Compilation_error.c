#include<iostream>
#include<string>
using namespace  std;


void trans(int q)
{

    
    string Octal;
    char decimal[1000];
    /*
    ①   八进制转换十进制时
        从后往前，每次取出每一位的数（8）
        将其与上一次除法运算得到的商相加
        再除以8
    */
    cin >> Octal;
    int num;//记录十位数
    int len = Octal.length() - 1;
    int Dlen = 0;//记录十进制数的位数

    for(; len != 1; len--)
    {
        num = Octal[len] - '0';
        int digit = 0;//记录mod之后的数
        int j = 0;//从前往后
        do
        {
            int temp;
            if(j < Dlen)
            {
                temp = num * 10 + decimal[j] - '0';
            }
            else
            {
                temp = num * 10;
                //后面没有存放的数据了，只能继续往后借0
            }
            digit = temp % 8;
            decimal[j++] = temp / 8 +'0';//别忘了j是要往后一位的，然后你是字符别忘记加0
            num = digit;
        }
        while(digit || j < Dlen);
        Dlen = j;//更新十进制的位数
    }
    
    cout << "case #" << q << ":" << endl <<"0.";
    for(int i = 0; i < Dlen; i++)
    {
        cout << decimal[i];
    }
    cout << endl;
}

int main()
{
    int total;
    cin >> total;
    for(int i = 0; i < total; i++)
    {
        trans(i);
    }
}
————————————————
版权声明：本文为CSDN博主「JamSlade」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/JamSlade/article/details/114439779