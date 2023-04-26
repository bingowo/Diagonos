#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define M 10000
char s[1005];
int a,b,n,l;
struct node {
	int num[1005],cnt,flg;
} A,B,A1,B1;
void out(struct node x){
	if(x.flg==-1) putchar('-');
	for(int i=x.cnt;i;i--) printf("%04d",x.num[i]);
	puts("");
}
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
}
void oper(struct node* T,struct node x,int val1,struct node y,int val2) {
	multi(&x,val1),multi(&y,val2);
	int pos=x.cnt;
	if(pos<y.cnt) pos=y.cnt;
	for(int i=x.cnt+1; i<=pos+2; i++) x.num[i]=0;
	for(int i=y.cnt+1; i<=pos+2; i++) y.num[i]=0;
	//out(x),out(y),printf("?? %d\n",pos);
	T->flg=0;
	for(int i=pos; i; i--) {
		T->num[i]=x.num[i]*x.flg+y.num[i]*y.flg;
		if(T->num[i]!=0&&T->flg==0) {
			if(T->num[i]>0) T->flg=1;
			else T->flg=-1;
		}
		T->num[i]*=T->flg;
	}
	for(int i=1; i<=pos; i++) {
		while(T->num[i]<0) T->num[i]+=M,T->num[i+1]--;
		if(T->num[i]>=M) T->num[i+1]+=T->num[i]/M,T->num[i]%=M;
	}
	//printf("AA %d\n",T->flg);
	pos+=2;
	while(T->num[pos]==0 && pos>1) pos--;
	T->cnt=pos;
}

int main() {
	scanf("%s%d",s,&n);
	if(n==0) printf("1"),exit(0);
	l=strlen(s);
	if(s[l-1]!='i') a=atoll(s),b=0;
	else {
		for(int i=l-1; i>=0; i--)
			if(s[i]=='+'||s[i]=='-'||i==0) {
				if(s[i+1]=='i') b=s[i]=='+'?1:-1;
				else if(s[i]=='i') b=1;
				else s[l-1]='\0',b=atoll(s+i);
				if(i!=0) s[i]='\0',a=atoll(s);
				else a=0;
				break;
			}
	}
	init(&A,a),init(&B,b);
	for(int i=1; i<n; i++) {
		oper(&A1,A,a,B,-b);
		oper(&B1,A,b,B,a);
		A=A1,B=B1;
//		printf("!! %d\n",i+1);
//		if(A.cnt!=1||A.num[1]!=0) {
//			if(A.flg==-1) printf("-");
//			printf("%d",A.num[A.cnt]);
//			for(int j=A.cnt-1; j; j--) printf("%04d",A.num[j]);
//		}
//		if(B.cnt!=1||B.num[1]!=0) {
//			if(B.flg==-1) printf("-");
//			else if(A.cnt!=1||A.num[1]!=0) printf("+");
//			printf("%d",B.num[B.cnt]);
//			for(int j=B.cnt-1; j; j--) printf("%04d",B.num[j]);
//			putchar('i');
//		}
//		puts("");
	}
	if(A.cnt!=1||A.num[1]!=0) {
		if(A.flg==-1) printf("-");
		printf("%d",A.num[A.cnt]);
		for(int i=A.cnt-1; i; i--) printf("%04d",A.num[i]);
	}
	if(B.cnt!=1||B.num[1]!=0) {
		if(B.flg==-1) printf("-");
		else if(A.cnt!=1||A.num[1]!=0) printf("+");
		if(B.num[1]!=1 || B.cnt!=1) {
			printf("%d",B.num[B.cnt]);
			for(int i=B.cnt-1; i; i--) printf("%04d",B.num[i]);
		}
		putchar('i');
	}
	return 0;
}