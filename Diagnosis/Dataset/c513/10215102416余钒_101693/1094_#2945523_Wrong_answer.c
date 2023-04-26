#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct node {
	int cnt,num[1005];
};
void init(struct node* x,char* s) {
	int l=strlen(s),pos=0;
	for(int i=l-1;i>=0;i--) x->num[++pos]=s[i]-'0';
	x->cnt=pos;
}
int cmp(struct node* x,struct node* y){
	if(x->cnt>y->cnt) return 1;
	else if(x->cnt<y->cnt) return -1;
	for(int i=x->cnt;i;i--) 
		if(x->num[i]>y->num[i]) return 1;
		else return -1;
	return 0;
}
void subs(struct node* x,struct node* y){
	for(int i=y->cnt+1;i<=x->cnt;i++) y->num[i]=0;
	for(int i=x->cnt;i;i--) x->num[i]-=y->num[i];
	for(int i=1;i<=x->cnt;i++){
		if(x->num[i]<0) x->num[i]+=10,x->num[i+1]--;
	}
	while(x->num[x->cnt]==0 && x->cnt>1) x->cnt--;
}
void out(struct node* x){
	for(int i=x->cnt;i;i--) printf("%d",x->num[i]);
	puts("");
}

int main() {
	char s[1005];
	int n,l;
	struct node A,MIN,MAX;
	scanf("%d",&n);
	MIN.cnt=1000;MAX.cnt=0;
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		init(&A,s);
		if(cmp(&A,&MAX)==1) MAX=A;
		if(cmp(&MIN,&A)==1) MIN=A;
	}
	//out(&MAX),out(&MIN);
	subs(&MAX,&MIN);
	out(&MAX);
	return 0;
}