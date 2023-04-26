#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct note{
    int cnt;  //记录数字的位数
    vector<int> num;  //记录每一位上面的数字
};

void div_2(note *m) //进行除以2的算法
{
    int a = 0; //判断是否可以除以2后，余数非负
    int b;
    if(m->num[m->cnt-1]<2){ //余数为负，a = 1
        m->cnt--;
        a = 1;
    }
    for(int i=m->cnt-1;i>-1;i--){
        b = 10*a+m->num[i];
        m->num[i] = b/2;
        a = b%2;
    }
}

void add(note *m)  //加1操作
{
    int a = 0;
    int i = 1;
    m->num[0] += 1;
    a = m->num[0]/10;
    m->num[0] %= 10;
    while(a !=0 &&i<m->cnt)
    {
        m->num[i] += a;
        a = m->num[i]/10;
        m->num[i] %= 10;
        i++;
    }
    if(a != 0){
        m->num[i] = a;
        m->cnt++;
    }

}

int main()
{
    string n; //需要进行转换的数字
    int remainder;  //表示余数
    int sign = 1;  //记录正负号，1为正数，-1为负数
    vector<int> res;
    note m;
    m.cnt = 0;
    cin>>n;

    //将string n记录在struct note中
    string::iterator i;  //反向迭代器
	for (i = n.end()-1; i >= n.begin()+1; i--){  //倒序
        m.num.push_back(*i-'0');
        m.cnt++;
	}
	if(*i == '-'){ //判断该字符串有无负号
        sign = -1;
	}else{
        m.num.push_back(*i-'0');
        m.cnt++;
	}

	//测试程序
    /*vector<int>::reverse_iterator h;  //反向迭代器
	for (h = m.num.rbegin(); h != m.num.rend(); h++){  //倒序输出
		cout<<*h;
	}
    cout<<endl;*/

    while(m.cnt>0){
        remainder = m.num[0]%2;
        res.push_back(remainder);
        div_2(&m);
        if(sign == -1 && remainder!=0){
            if(m.cnt == 0){
                m.cnt++;
                m.num[0] = 1;
            }else add(&m);
        }
        sign = -sign;
    }

    //最终的输出
    vector<int>::reverse_iterator it;  //反向迭代器
	for (it = res.rbegin(); it != res.rend(); it++){  //倒序输出
		cout<<*it;
	}
    cout<<endl;
    return 0;
}
