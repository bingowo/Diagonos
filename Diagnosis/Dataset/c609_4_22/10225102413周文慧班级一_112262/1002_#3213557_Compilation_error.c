#include<iostream.h>

using namespace std;

int max_len_dif(long long a)
{
    int fir = a % 2,sec;
    int count = 1;
    int temp = 1;
    while(a)
    {   
        
        a >>= 1;
        sec = a % 2;
        if(sec != fir)
        {temp++;}
        else
        {
            if(temp > count)
                {count = temp;}
            temp = 1;
        }
        
        fir = sec;
    }

    if(temp > count){count = --temp;}
    //需要注意的是，如果在while循环没有重新初始化，需要在while循环外面再单独处理
    return count;
}


int main()
{
    int total;
    cin >> total;
    for(int i = 0; i < total; i++)
    {
        long long a;
        cin >> a;
        cout << "case #" << i << ":"<<endl;
        cout << max_len_dif(a) << endl; 
    }

    return 0;
}