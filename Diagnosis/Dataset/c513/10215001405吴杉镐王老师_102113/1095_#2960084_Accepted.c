#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 100000000
char s[10005]; 
int pow[4][2]={1,0,-1,1,0,-2,2,2};
struct node {
	long long num[1005];
	int cnt,flg;
} A,B,BASE,tmp;
void init(struct node* x,int val) {
	x->cnt=1,x->num[1]=val;
	if(val<0) x->flg=-1,x->num[1]*=-1;
	else x->flg=1;
}
void multi(struct node* x,int val) {
	if(val<0) x->flg*=-1,val=-val;
	x->num[x->cnt+1]=0;
	for(int i=1; i<=x->cnt; i++) x->num[i]*=val;
	for(int i=1; i<=x->cnt; i++) x->num[i+1]+=x->num[i]/M,x->num[i]%=M;
	if(x->num[x->cnt+1]>0) x->cnt++;
	while(x->num[x->cnt]==0 && x->cnt>1) x->cnt--;
}
void oper(struct node* T,struct node x,int val1,struct node y,int val2) {
	multi(&x,val1),multi(&y,val2);
	int pos=1000;
	for(int i=x.cnt+1; i<=1000; i++) x.num[i]=0;
	for(int i=y.cnt+1; i<=1000; i++) y.num[i]=0;
	T->flg=0;
	for(int i=1000; i; i--) {
		T->num[i]=x.num[i]*x.flg+y.num[i]*y.flg;
		if(T->num[i]!=0 && T->flg==0) {
			if(T->num[i]>0) T->flg=1;
			else T->flg=-1;
		}
		T->num[i]*=T->flg;
	}
	for(int i=1; i<1000; i++) {
		while(T->num[i]<0) T->num[i]+=M,T->num[i+1]--;
		if(T->num[i]>=M) T->num[i+1]+=T->num[i]/M,T->num[i]%=M;
	}
	while(T->num[pos]==0 && pos>1) pos--;
	T->cnt=pos;
}
int main() {
	scanf("%s",s);
	int l=strlen(s);
	init(&A,0),init(&B,0),init(&BASE,1);
	for(int i=l-1;i>1;i--){
		int val=s[i]-'0';
		if(s[i]>='A'&&s[i]<='F') val=s[i]-'A'+10;
		for(int p=0;p<4;p++)
			if(val&(1<<p)) oper(&A,A,1,BASE,pow[p][0]),oper(&B,B,1,BASE,pow[p][1]);
		multi(&BASE,-4);
	}
	if(A.cnt!=1||A.num[1]!=0) {
		if(A.flg==-1) printf("-");
		printf("%lld",A.num[A.cnt]);
		for(int i=A.cnt-1; i; i--) printf("%08lld",A.num[i]);
	}
	if(B.cnt!=1||B.num[1]!=0) {
		if(B.flg==-1) printf("-");
		else if(A.cnt!=1||A.num[1]!=0) printf("+");
		if(B.num[1]!=1 || B.cnt!=1) {
			printf("%lld",B.num[B.cnt]);
			for(int i=B.cnt-1; i; i--) printf("%08lld",B.num[i]);
		}
		putchar('i');
	}
	if(B.cnt==1&&B.num[1]==0&&A.cnt==1&&A.num[1]==0) putchar('0');
	return 0;
}