#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> pri_num(int a)  //统计小于a的所有质数
{
    int i = 3; //从3开始,因为1不是质数,单独讨论2
    vector<int> prime;
    if(a == 2){
        prime.push_back(2);
        return prime;
    }else prime.push_back(2);
    while(i <= a){
        int sqrt_i = (int)sqrt((double)i);
        bool m = 1; //标记是否为素数
        if(i%2 == 0){ //如果i是偶数,直接判断不是质数,i++,且继续循环
            i++;
            continue;
        }else{
            for(int j = 2;j<sqrt_i;j++){
                if(i%j == 0) m = 0;
                if(m == 0) break;
            }
            if(m == 1) prime.push_back(i);
            i++;
        }

    }
    return prime;
}

int main()
{
    int a; //进行计算的数
    int sqrt_a;
    cin>>a;
    if(a == 1){ //单独讨论1时
        cout<<"0"<<endl;
        return 0;
    }else{  //a不为0的情况,即0<a<=1000


    }

    return 0;
}
