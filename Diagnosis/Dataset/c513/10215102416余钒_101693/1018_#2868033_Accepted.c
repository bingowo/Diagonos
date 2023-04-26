#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int base=1000,a[105];
int pri[30]={0, 2, 3, 5 ,7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
char s[3005];
struct BIG{
	int A[1005],pos;
}res,ans,mul;
void multi(struct BIG* x,int val,struct BIG* y){
	for(int i=1;i<=x->pos;i++)
		y->A[i]=x->A[i]*val;
	int up=0;
	for(int i=1;i<=x->pos;i++)
		y->A[i]+=up,up=y->A[i]/10000,y->A[i]%=10000;
	y->pos=x->pos;
	if(up) y->A[++y->pos]=up;
}
void add(struct BIG* x,struct BIG* y){
	int up=0,l=x->pos;
	if(l<y->pos) l=y->pos;
	for(int i=1;i<=l;i++){
		x->A[i]=x->A[i]+y->A[i]+up;
		up=x->A[i]/10000;
		x->A[i]%=10000;
	}
	if(up) x->A[++l]=up;
	x->pos=l;
}
void out(struct BIG* x){
	for(int i=x->pos;i;i--){
		if(i==x->pos || x->A[i]>999)printf("%d",x->A[i]);
		else if(x->A[i]>99) printf("0%d",x->A[i]);
		else if(x->A[i]>9) printf("00%d",x->A[i]);
		else printf("000%d",x->A[i]);
	}
		
	puts("");
}
int main() {
	for(int i=1;i<=1000;i++) res.A[i]=ans.A[i]=mul.A[i]=0;
	scanf("%s",s);
	int cnt=0,las=0;
	for(int i=0;s[i]!='\0';i++){
		if(s[i]==',') a[++cnt]=las,las=0;
		else las=las*10+s[i]-'0';
	}
	a[++cnt]=las;
	for(int i=1;i<=cnt/2;i++)
		las=a[i],a[i]=a[cnt-i+1],a[cnt-i+1]=las;
	res.pos=1,res.A[1]=1;
	for(int i=1;i<=cnt;i++){
		multi(&res,a[i],&mul);
		add(&ans,&mul);
		multi(&res,pri[i],&res);
	}
	out(&ans);
	return 0;
}