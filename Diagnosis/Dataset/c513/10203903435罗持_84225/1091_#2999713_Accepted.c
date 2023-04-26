#include <stdio.h>
#include <string.h>
#define N 5000
typedef struct{
	int cnt;
	int v[N];
	int sign;
}BIGINT;
typedef struct{
	BIGINT re,im;
}COMPLEX;
void init(COMPLEX *data,char *s){
	int len = strlen(s);
	int j = len-1;
	if(s[j]=='i'){
		if(j==0){
			data->im.v[0] = 1;
			data->im.sign = 1;
			data->im.cnt = 1;
			return;
		}
		j--;
		if(s[j]=='-' || s[j]=='+'){
			data->im.v[data->im.cnt++] = 1;
		}
		else{
			while(j>=0 && s[j]>='0'&&s[j]<='9'){
				data->im.v[data->im.cnt++] = s[j]-'0';
				j--;
			}
		}
		if(j>=0){
			if(s[j]=='-') data->im.sign = -1;
			j--;
		}
	}
	while(j>=0 && s[j]>='0' && s[j]<='9'){
		data->re.v[data->re.cnt++] = s[j]-'0';
		j--;
	}
	if(j>=0){
		if(s[j]=='-') data->re.sign = -1;
	}
}
void print(COMPLEX *result){
	if(result->re.cnt!=0){
		if(result->re.sign==-1) printf("-");
		for(int i=result->re.cnt-1;i>=0;i--) 
			printf("%d",result->re.v[i]);
		if(result->im.cnt!=0 && result->im.sign==1) printf("+");
	}
	if(result->im.cnt!=0){
		if(result->im.sign==-1) printf("-");
		if(result->im.cnt==1 && result->im.v[0]==1) printf("i\n");
		else{
			for(int i=result->im.cnt-1;i>=0;i--)
				printf("%d",result->im.v[i]);
			printf("i\n");
		}
	}
}
BIGINT BIGMUL(BIGINT a,BIGINT b){
	BIGINT R = {0,{0},1};
	if(a.cnt==0 || b.cnt==0) return R;
	R.cnt = a.cnt+b.cnt;
	R.sign = a.sign*b.sign;
	for(int i=0;i<b.cnt;i++){
		int t,k,j;
		int carry = 0;
		for(j=0;j<a.cnt;j++){
			t = a.v[j] * b.v[i]+carry + R.v[i+j];
			R.v[i+j] = t%10;
			carry = t/10;
		}
		k = i+j;
		while(carry>0){
			t = carry + R.v[k];
			R.v[k] = t%10;
			carry = t/10;
			k++;
		}
	}
	if(R.v[a.cnt+b.cnt-1]==0) R.cnt--;
	return R;
}
int cmp(BIGINT a,BIGINT b){
	int n = (a.cnt>b.cnt)?a.cnt:b.cnt;
	for(int i=n-1;i>=0;i--){
		if(*(a.v+i)>*(b.v+i)) return 1;
		else if(*(a.v+i)<*(b.v+i)) return -1;
	}
	return 0;
}
void SUB(BIGINT *a,BIGINT *b,BIGINT *r){
	int n = (a->cnt > b->cnt)?a->cnt:b->cnt;
	r->cnt = n;
	int carry = 0,i=0;
	for(i=0;i<n;i++){
		if(*(a->v+i)+carry<*(b->v+i)){
			int temp = 10+*(a->v+i)-*(b->v+i)+carry;
			carry = -1;
			*(r->v+i) = temp;
		}
		else{
			int temp = *(a->v+i)-*(b->v+i)+carry;
			carry = 0;
			*(r->v+i) = temp;
		}
	}
	for(int i=n-1;i>=0 && !r->v[i];i--) r->cnt--;
}
BIGINT BIGSUB(BIGINT a,BIGINT b){
	BIGINT R = {0,{0},1};
	if(cmp(a,b)>=0){
		R.sign = 1;
		SUB(&a,&b,&R);
	}
	else{
		R.sign = -1;
		SUB(&b,&a,&R);
	}
	return R;
}
BIGINT BIGADD(BIGINT a,BIGINT b){
	if(a.cnt==0) return b;
	if(b.cnt==0) return a;
	BIGINT R = {0,{0},1};
	if(a.sign * b.sign<0){
		if(a.sign==-1) R = BIGSUB(b,a);
		else R = BIGSUB(a,b);
	}
	else{
		R.sign = a.sign;
		int i=0, carry = 0;
		for(i=0;i<a.cnt && i<b.cnt;i++){
			int temp = carry+a.v[i]+b.v[i];
			R.v[i] = temp%10;
			carry = temp/10;
		}
		while(i<a.cnt){
			int temp = carry + a.v[i];
			R.v[i++] = temp%10;
			carry = temp/10;
		}
		while(i<b.cnt){
			int temp = carry + b.v[i];
			R.v[i++] = temp%10;
			carry = temp/10;
		}
		if(carry){
			R.v[i++] = carry%10;
		}
		R.cnt = i;
	}
	return R;
}
COMPLEX mul(COMPLEX a,COMPLEX b){
	COMPLEX result = {{0,{0},1},{0,{0},1}};
	BIGINT re1 = BIGMUL(a.re,b.re);
	BIGINT re2 = BIGMUL(a.im,b.im);
	re2.sign = -re2.sign;
	BIGINT im1 = BIGMUL(a.re,b.im);
	BIGINT im2 = BIGMUL(a.im,b.re);
	result.im = BIGADD(im1,im2);
	result.re = BIGADD(re1,re2);
	return result;
}
void pow_Comp(COMPLEX *data,int n){
	COMPLEX p = {{1,{1},1},{0,{0},1}};
	for(int i=1;i<=n;i++) p = mul(p,*data);
	*data = p;
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