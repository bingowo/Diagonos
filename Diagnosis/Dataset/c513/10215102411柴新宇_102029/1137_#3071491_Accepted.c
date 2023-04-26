#include <stdio.h>
#include <string.h>
typedef struct{
	int cnt;
	int v[5000];
	int sign;
}BIGINT;
int cmp(BIGINT a, BIGINT b){
	int n = (a.cnt > b.cnt)?a.cnt:b.cnt;
	for(int i=n-1;i>=0;i--){
		if(*(a.v+i)>*(b.v+i)) return 1;
		else if(*(a.v+i)<*(b.v+i)) return -1;
	}
	return 0;
}
void SUB(BIGINT *a,BIGINT *b,BIGINT *r){
	int n = (a->cnt > b->cnt)?a->cnt:b->cnt;
	r->cnt = n;
	int carry = 0, i = 0;
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
	if(a.sign * b.sign < 0){
		if(a.sign==-1) R = BIGSUB(b,a);
		else R = BIGSUB(a,b);
	}
	else{
		R.sign = a.sign;
		int i = 0, carry = 0;
		for(i=0;i<a.cnt & i<b.cnt;i++){
			int temp = carry + a.v[i] + b.v[i];
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
		if(carry) R.v[i++] = carry%10;
		R.cnt = i;
	}
	return R;
}
BIGINT a = {0,{0},1},b = {0,{0},1};
char sa[1000], sb[1000];
int main(void)
{
	scanf("%s %s",sa,sb);
	int st = 0;
	if(sa[0]=='-'){
		st = 1;
		a.sign = -1;
	}
	for(int i=strlen(sa)-1;i>=st;i--){
		a.v[a.cnt++] = sa[i]-'0';
	}
	st = 0;
	if(sb[0]=='-'){ 
		st = 1;
		b.sign = -1;
	}
	for(int i=strlen(sb)-1;i>=st;i--){
		b.v[b.cnt++] = sb[i]-'0';
	}
	/*if(a.sign==-1) printf("-");
	for(int i=a.cnt-1;i>=0;i--){
		printf("%d",a.v[i]);
	}
	putchar('\n');
	if(b.sign==-1) printf("-");
	for(int i=b.cnt-1;i>=0;i--){
		printf("%d",b.v[i]);
	}
	putchar('\n');*/
	BIGINT res = BIGADD(a,b);
	if(res.cnt==0){
		printf("0");
		return 0;
	}
	if(res.sign==-1) printf("-");
	for(int i=res.cnt-1;i>=0;i--){
		printf("%d",res.v[i]);
	}
	return 0;
}
