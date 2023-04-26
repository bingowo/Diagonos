#include <stdio.h>
#include <string.h>
typedef struct{
	int cnt;
	int v[200];
	int sign;
}BIGINT;
int N;
int cmp(BIGINT a,BIGINT b){
	if(a.sign!=b.sign){
		if(a.sign>b.sign) return 1;
		else return -1;
	}
	if(a.sign==1 && b.sign==1){
		int n = (a.cnt>b.cnt)?a.cnt:b.cnt;
		for(int i=n-1;i>=0;i--){
			if(a.v[i]>b.v[i]) return 1;
			else if(a.v[i]<b.v[i]) return -1;
		}
		return 0;
	}
	else{
		int n = (a.cnt>b.cnt)?a.cnt:b.cnt;
		for(int i=n-1;i>=0;i--){
			if(a.v[i]>b.v[i]) return -1;
			else if(a.v[i]<b.v[i]) return 1;
		}
		return 0;
	}
}
BIGINT BIGADD(BIGINT a,BIGINT b){
	BIGINT R = {0,{0},1};
	if(a.cnt==0) return b; 
	if(b.cnt==0) return a;
	int i, carry = 0;
	for(i=0;i<a.cnt&&i<b.cnt;i++){
		int temp = a.v[i]+b.v[i]+carry;
		R.v[i] = temp%10;
		carry = temp/10;
	}
	while(i<a.cnt){
		int temp = carry+a.v[i];
		R.v[i++] = temp%10;
		carry = temp/10;
	}
	while(i<b.cnt){
		int temp = carry+b.v[i];
		R.v[i++] = temp%10;
		carry = temp/10;
	}
	if(carry) R.v[i++] = carry%10;
	R.cnt = i;
	return R;
}
void sub(BIGINT *a,BIGINT *b,BIGINT *R){
	int n = (a->cnt>b->cnt)?a->cnt:b->cnt;
	R->cnt = n;
	int carry = 0, i;
	for(i=0;i<n;i++){
		if((*(a->v+i)+carry)<(*(b->v+i))){
			*(R->v+i) = 10+*(a->v+i)+carry-*(b->v+i);
			carry = -1;
		}
		else{
			*(R->v+i) = *(a->v+i)+carry - *(b->v+i);
			carry = 0; 
		}
	}
	for(int i=n-1;i>=0&&!R->v[i];i--) R->cnt--;
}
BIGINT BIGSUB(BIGINT a,BIGINT b){
	BIGINT R = {0,{0},1};
	if(a.sign!=b.sign){
		a.sign = 1, b.sign = 1;
		R = BIGADD(a,b);
	} 
	else{
		if(a.sign==1 && b.sign==1) sub(&a,&b,&R);
		else sub(&b,&a,&R);
	}
	return R;
}
int main(void)
{
	scanf("%d",&N);
	BIGINT MAX,MIN;
	MAX.cnt = 150, MIN.cnt = 150;
	for(int i=0;i<150;i++){
		MAX.v[i] = 9;
		MIN.v[i] = 9;
	}
	MAX.sign = -1,MIN.sign = 1;
	while(N--){
		BIGINT NOW = {0,{0},1};
		char s[150] = {0};
		scanf("%s",s);
		int ed = 0;
		int len= strlen(s);
		if(s[0]=='-'){
			NOW.sign = -1;
			ed = 1;
		}
		for(int i=len-1;i>=ed;i--)
			NOW.v[NOW.cnt++] = s[i]-'0';
		if(cmp(NOW,MAX)>0) MAX = NOW;
		if(cmp(NOW,MIN)<0) MIN = NOW;
	}
	BIGINT R = BIGSUB(MAX,MIN);
	for(int i=R.cnt-1;i>=0;i--)
		printf("%d",R.v[i]);
	/*for(int i=MAX.cnt-1;i>=0;i--)
		printf("%d",MAX.v[i]);
	putchar('\n');
	for(int i=MIN.cnt-1;i>=0;i--)
		printf("%d",MIN.v[i]);*/
	return 0;
}