#include<iostream>
#include<string>
#include<vector>
const int MAXLEN = 402; 
struct BIGINT{
	int cnt;
	std::vector<int> num;
};
void ADD1 (BIGINT* p);
void DIV2 (BIGINT* p);
int main(){
	BIGINT p;
	std::string s;
	std::cin>>s;
	int len = s.length();
	int sign = 1;
	p.cnt = 0;
	for(std::string::reverse_iterator i = s.rbegin();i != s.rend()-1;i++){         //s.end()-1   去除最后一个元素 
		p.num.push_back(*i - '0');       			      //字符串数值转换 
		p.cnt++;
	}
	if(s[0] == '-')
		sign = -1;
	else{
		p.num.push_back(s[0] - '0');   
		p.cnt++;
	}
	std::vector<int> bin(MAXLEN, 0);
	int cnt = 0;
	while(p.cnt > 0){
		bin[cnt++] = p.num[0] % 2;
		if(sign == -1 && bin[cnt-1]){          
			ADD1(&p);	
		} 
		DIV2(&p);
		sign *= -1;
	}
	for(int i = cnt - 1;i >= 0;i--){
		std::cout<<bin[i];
	}
	std::cout<<'\n';
	return 0;
} 
void ADD1 (BIGINT* p){
	p->num[0]++;
	int carry = 0;
	for(int i = 0;i < p->cnt;i++){
		p->num[i] += carry;
		carry = p->num[i] / 10;
		p->num[i] %= 10;
	}
	if(carry)
		p->num[p->cnt++] = carry;                  //进位改变位数 
}
void DIV2 (BIGINT* p){
	int carry = 0;
	if(p->num[p->cnt-1] < 2){              	  //首位可能为0 
		p->cnt--;                             //改变cnt,for loop仍从cnt-1开始 
		carry = 1;
	}
	for(int i = p->cnt-1;i >= 0;i--){
		int tot = 10 * carry + p->num[i];
		carry = tot % 2;
		p->num[i] = tot / 2; 
	}
}