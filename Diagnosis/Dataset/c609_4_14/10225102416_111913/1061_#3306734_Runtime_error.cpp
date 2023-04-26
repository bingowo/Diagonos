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
            for(int j = 2;j<=sqrt_i;j++){
                if(i%j == 0) m = 0;
                if(m == 0) break;
            }
            if(m == 1) prime.push_back(i);
            i++;
        }

    }
    return prime;
}

/*long long CNT(int a,int prime)
{
    static long long m[1001][1001];
    vector<int>::iterator i = prime.begin();; //定义正向迭代器
    int t,k=0;
    if (!m[a][*i])
        if(!a) m[a][*i]=1;
        else if(a>=*i){
            while((t=a-*i*k++)>=0){
                i++;
                m[a][*i]+=CNT(t,i);
            }
        }
    return m[a][*i];

}*/

int main()
{
    int a; //进行整数分解的数
    vector<long long> cnt(100,0);
    cnt[0] = 1;
    vector<int> prime;
    int len;
    int i = 0;
    int j;
    cin>>a;
    prime = pri_num(a);
    len = end(prime) - begin(prime);
    if(a == 1){ //单独讨论1时
        cout<<"0"<<endl;
        return 0;
    }else{  //a不为0的情况,即1<a<=1000
        for(i = 0;i<len;i++){
            for(j = prime[i];j<=a;j++){
                cnt[j] += cnt[j - prime[i]];
            }
        }
    }
    /*j = 0;
    for(auto e:cnt){
        cout<<"cnt[%d]"<<j<<":"<<e<<endl;
        j++;
    }*/
    cout<<cnt[a];
    return 0;
}
