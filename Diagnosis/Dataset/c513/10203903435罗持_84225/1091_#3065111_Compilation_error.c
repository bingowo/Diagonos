#include <bits/stdc++.h>
using namespace std;
class BIGINT{
	public:
		int _cnt;
		int _v[200];
		int _sign;
		BIGINT(int cnt,int v[], int sign);
		BIGINT(const BIGINT &other);
		BIGINT(BIGINT &&other);
		BIGINT& operator= (BIGINT &other);
		BIGINT& operator= (BIGINT &&other);
		~BIGINT();
		int get_cnt() const;
		int get_sign() const;
		int get_digit(int idx) const;
		friend class COMPLEX;
		friend BIGINT operator+ (BIGINT a,BIGINT b);
		friend BIGINT operator- (BIGINT a,BIGINT b);
		friend BIGINT operator* (BIGINT a,BIGINT b);
		friend int cmp(BIGINT a,BIGINT b);
		friend void SUB(BIGINT *a,BIGINT *b,BIGINT *r);
		friend void print(BIGINT a);
};
class COMPLEX{
	private:
		BIGINT _re,_im;
	public:
		COMPLEX(BIGINT re,BIGINT im);
		COMPLEX(const COMPLEX &other);
		COMPLEX(COMPLEX &&other);
		COMPLEX& operator= (COMPLEX &other);
		COMPLEX& operator= (COMPLEX &&other);
		~COMPLEX();
		BIGINT get_re() const;
		BIGINT get_im() const;
		friend void init(COMPLEX* other,char *s);
		friend void print(COMPLEX* other);
		friend void pow_Comp(COMPLEX *data,int n);
		friend COMPLEX mul(COMPLEX a, COMPLEX b);
};
BIGINT::BIGINT(int cnt,int v[], int sign){
	_cnt = cnt;
	for(int i=0;i<_cnt;i++)
		_v[i] = v[i];
	_sign = sign;
}
BIGINT::BIGINT(const BIGINT &other){
	_cnt = other.get_cnt();
	_sign = other.get_sign();
	for(int i=0;i<_cnt;i++)
		_v[i] = other.get_digit(i);
}
BIGINT::BIGINT(BIGINT &&other){
	_cnt = other.get_cnt();
	_sign = other.get_sign();
	for(int i=0;i<_cnt;i++)
		_v[i] = other.get_digit(i);
}
BIGINT& BIGINT::operator= (BIGINT &other){
	if(this!=&other){
		_cnt = other.get_cnt();
		_sign = other.get_sign();
		for(int i=0;i<_cnt;i++)
			_v[i] = other.get_digit(i);
	}
	return *this;
}
BIGINT& BIGINT::operator= (BIGINT &&other){
	if(this!=&other){
		_cnt = other.get_cnt();
		_sign = other.get_sign();
		for(int i=0;i<_cnt;i++)
			_v[i] = other.get_digit(i);
	}
	return *this;
}
BIGINT::~BIGINT(){}
int BIGINT::get_cnt() const{
	return _cnt;
}
int BIGINT::get_sign() const{
	return _sign;
} 
int BIGINT::get_digit(int idx) const{
	if(idx>=_cnt) cout << "Wonrg" << endl;
	return _v[idx];
}
BIGINT operator+ (BIGINT a,BIGINT b){
	if(a._cnt==0) return b;
	if(b._cnt==0) return a;
	BIGINT R = {0,{0},1};
	if(a._sign * b._sign<0){
		if(a._sign==-1) R = b-a;
		else R = a-b;
	}
	else{
		R._sign = a._sign;
		int i=0, carry = 0;
		for(i=0;i<a._cnt && i<b._cnt;i++){
			int temp = carry+a._v[i]+b._v[i];
			R._v[i] = temp%10;
			carry = temp/10;
		}
		while(i<a._cnt){
			int temp = carry + a._v[i];
			R._v[i++] = temp%10;
			carry = temp/10;
		}
		while(i<b._cnt){
			int temp = carry + b._v[i];
			R._v[i++] = temp%10;
			carry = temp/10;
		}
		if(carry){
			R._v[i++] = carry%10;
		}
		R._cnt = i;
	}
	return R;
}
BIGINT operator- (BIGINT a,BIGINT b){
	BIGINT R = {0,{0},1};
	if(cmp(a,b)>=0){
		R._sign = 1;
		SUB(&a,&b,&R);
	}
	else{
		R._sign = -1;
		SUB(&b,&a,&R);
	}
	return R;
}
BIGINT operator* (BIGINT a,BIGINT b){
	BIGINT R = {0,{0},1};
	if(a._cnt==0 || b._cnt==0) return R;
	R._cnt = a._cnt+b._cnt;
	for(int i=0;i<R._cnt;i++) R._v[i] = 0;
	R._sign = a._sign*b._sign;
	for(int i=0;i<b._cnt;i++){
		int t,k,j;
		int carry = 0;
		for(j=0;j<a._cnt;j++){
			t = a._v[j] * b._v[i]+carry + R._v[i+j];
			//cout << "temp = " << a._v[j] << ' ' << b._v[i] << ' ' << carry << ' ' << R._v[i+j] << endl;
 			R._v[i+j] = t%10;
			carry = t/10;
		}
		k = i+j;
		while(carry>0){
			t = carry + R._v[k];
			R._v[k] = t%10;
			carry = t/10;
			k++;
		}
	}
	if(R._v[a._cnt+b._cnt-1]==0) R._cnt--;
	return R;
}
int cmp(BIGINT a,BIGINT b){
	int n = (a._cnt>b._cnt)?a._cnt:b._cnt;
	for(int i=n-1;i>=0;i--){
		if(*(a._v+i)>*(b._v+i)) return 1;
		else if(*(a._v+i)<*(b._v+i)) return -1;
	}
	return 0;
}
void SUB(BIGINT *a,BIGINT *b,BIGINT *r){
	int n = (a->_cnt > b->_cnt)?a->_cnt:b->_cnt;
	r->_cnt = n;
	int carry = 0,i=0;
	for(i=0;i<n;i++){
		if(*(a->_v+i)+carry<*(b->_v+i)){
			int temp = 10+*(a->_v+i)-*(b->_v+i)+carry;
			carry = -1;
			*(r->_v+i) = temp;
		}
		else{
			int temp = *(a->_v+i)-*(b->_v+i)+carry;
			carry = 0;
			*(r->_v+i) = temp;
		}
	}
	for(int i=n-1;i>=0 && !r->_v[i];i--) r->_cnt--;
}
void print(BIGINT a){
	if(a._sign==-1) cout << "-";
	for(int i=0;i<a.get_cnt();i++) cout << a._v[i];
	cout << endl;
}
COMPLEX::COMPLEX(BIGINT re,BIGINT im):_re(re), _im(im){}
COMPLEX::COMPLEX(const COMPLEX& other):_re(other.get_re()),_im(other.get_im()){}
COMPLEX::COMPLEX(COMPLEX&& other):_re(other.get_re()),_im(other.get_im()){}
COMPLEX& COMPLEX::operator= (COMPLEX& other){
	if(this!=&other){
		_re = other.get_re();
		_im = other.get_im();
	}
	return *this;
}
COMPLEX& COMPLEX::operator= (COMPLEX&& other){
	if(this!=&other){
		_re = other.get_re();
		_im = other.get_im();
	}
	return *this;
}
COMPLEX::~COMPLEX(){}
BIGINT COMPLEX::get_re() const{
	return _re;
}
BIGINT COMPLEX::get_im() const{
	return _im;
}
void init(COMPLEX* other,char *s){
	int len = strlen(s);
	int j = len-1;
	if(s[j]=='i'){
		if(j==0){
			other->_im._v[0] = 1;
			other->_im._sign = 1;
			other->_im._cnt = 1;
			return;
		}
		j--;
		if(s[j]=='-' || s[j]=='+'){
			other->_im._v[other->_im._cnt++] = 1;
		}
		else{
			while(j>=0 && s[j]>='0'&&s[j]<='9'){
				other->_im._v[other->_im._cnt++] = s[j]-'0';
				j--;
			}
		}
		if(j>=0){
			if(s[j]=='-') other->_im._sign = -1;
			j--;
		}
	}
	while(j>=0 && s[j]>='0' && s[j]<='9'){
		other->_re._v[other->_re._cnt++] = s[j]-'0';
		j--;
	}
	if(j>=0){
		if(s[j]=='-') other->_re._sign = -1;
	}
}
void print(COMPLEX* other){
	if(other->_re._cnt!=0){
		if(other->_re._sign==-1) printf("-");
		for(int i=other->_re._cnt-1;i>=0;i--) 
			printf("%d",other->_re._v[i]);
		if(other->_im._cnt!=0 && other->_im._sign==1) printf("+");
	}
	if(other->_im._cnt!=0){
		if(other->_im._sign==-1) printf("-");
		if(other->_im._cnt==1 && other->_im._v[0]==1) printf("i\n");
		else{
			for(int i=other->_im._cnt-1;i>=0;i--)
				printf("%d",other->_im._v[i]);
			printf("i\n");
		}
	}
}
void pow_Comp(COMPLEX *data,int n){
	int temp1[] = {1}, temp2[] = {0};
	COMPLEX p = {{1,temp1,1},{0,temp2,1}};
	for(int i=1;i<=n;i++){
		p = mul(p,*data);
		//cout << "i = " << i << ' ';
		//print(&p);
	}
	*data = p;
}
COMPLEX mul(COMPLEX a, COMPLEX b){
	COMPLEX result = {{0,{0},1},{0,{0},1}};
	//print(a._re);
	//print(a._im);	
	//print(b._re);
	//print(b._im);
	BIGINT re1 = a._re*b._re;
	BIGINT re2 = a._im*b._im;
	//print(re1);
	//print(re2);
	re2._sign = -re2._sign;
	BIGINT im1 = a._re*b._im;
	BIGINT im2 = a._im*b._re;
	//print(im1);
	//print(im2);
	result._im = im1+im2;
	result._re = re1+re2;
	return result;
}
int main(void)
{
	char s[20];
	int n;
	scanf("%s%d",s,&n);
	COMPLEX data = {{0,{0},1},{0,{0},1}};
	init(&data,s);
	if(n==0) printf("1\n");
	else if(n==1) print(&data);
	else{
		pow_Comp(&data,n);
		print(&data);
	}
	return 0;
}