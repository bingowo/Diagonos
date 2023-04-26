#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct node {
	int cnt,num[1005],flg;
};
void init(struct node* x,char* s) {
	int l=strlen(s),pos=0;
	for(int i=l-1;i>=0;i--) x->num[++pos]=s[i]-'0';
	if(s[0]=='-') pos--,x->flg=-1;
	else x->flg=1;
	x->cnt=pos;
}
int cmp(struct node* x,struct node* y){
	if(x->flg > y->flg) return 1;
	else if(x->flg < y->flg) return -1;
	if(x->cnt>y->cnt) return x->flg;
	else if(x->cnt<y->cnt) return -x->flg;
	for(int i=x->cnt;i;i--) 
		if(x->num[i]>y->num[i]) return x->flg;
		else if(x->num[i]<y->num[i]) return -x->flg;
	return 0;
}
void subs(struct node* x,struct node* y){
	int pos=x->cnt;
	if(pos<y->cnt) pos=y->cnt;
	pos+=2;
	for(int i=x->cnt+1;i<=pos;i++) x->num[i]=0;
	for(int i=y->cnt+1;i<=pos;i++) y->num[i]=0;
	int flg=0;
	for(int i=pos;i;i--){
		x->num[i]=x->num[i]*x->flg-y->num[i]*y->flg;
		if(flg==0 && x->num[i]!=0){
			if(x->num[i]>0) flg=1;
			else flg=-1;
		}
		x->num[i]*=flg;
	}
	if(flg==0) flg=1;
	for(int i=1;i<=pos;i++){
		while(x->num[i]<0) x->num[i]+=10,x->num[i+1]--;
		while(x->num[i]>9) x->num[i]-=10,x->num[i+1]++;
	}
	//while(x->num[pos]==0 && pos>1) pos--;
	x->flg=flg,x->cnt=pos;
}
void out(struct node* x){
	if(x->flg==-1&&(x->cnt!=0||x->num[1]!=0)) putchar('-');
	for(int i=x->cnt;i;i--) printf("%d",x->num[i]);
	puts("");
}

int main() {
	char s[1005];
	int n,l;
	struct node A,MIN,MAX;
	scanf("%d",&n);
	MIN.cnt=1000,MIN.flg=1;MAX.cnt=1000,MAX.flg=-1;
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		init(&A,s);
		//out(&A);
		if(cmp(&A,&MAX)==1) MAX=A;
		if(cmp(&MIN,&A)==1) MIN=A;
	}
	//out(&MAX),out(&MIN);
	subs(&MAX,&MIN);
	out(&MAX);
	return 0;
}