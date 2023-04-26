#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int stk[1005][2],top1=0,top2=0;
long long x,y;
int main() {
	for(int i=1;i<=1000;i++) stk[i][0]=stk[i][1]=0;
	scanf("%lld%lld",&x,&y);
	int op1=1,op2=1;
	if(x<0) x=-x,op1=-1;
	if(y<0) y=-y,op2=-1;
	while(x) stk[++top1][0]=x%2,x>>=1;
	while(y) stk[++top2][1]=y%2,y>>=1;
	if(top2>top1) top1=top2;
	for(int i=1;i<=top1;i++){
		if(stk[i][0]==1&&stk[i][1]==1){
			if(i==1) puts("-1"),exit(0);
			int pos=i+1;
			if(stk[i-1][0]==1){
				stk[i-1][0]=-1,stk[i][0]=0;
				stk[i+1][0]++;
				while(stk[pos][0]>1) stk[pos+1][0]+=stk[pos][0]/2,stk[pos][0]%=2,pos++;
				if(pos>top1 && stk[pos][0]>0) top1=pos; 
			}else if(stk[i-1][1]==1){
				stk[i-1][1]=-1,stk[i][1]=0;
				stk[i+1][1]++;
				while(stk[pos][1]>1) stk[pos+1][1]+=stk[pos][1]/2,stk[pos][1]%=2,pos++;
				if(pos>top1 && stk[pos][1]>0) top1=pos; 
			}else puts("-1"),exit(0);
		}
		else if(stk[i][0]==0&&stk[i][1]==0){
			if(i==1) puts("-1"),exit(0);
			if(stk[i-1][0]==1) stk[i-1][0]=-1,stk[i][0]=1;
			else stk[i-1][1]=-1,stk[i][1]=1;
		}
	}
	printf("%d\n",top1);
	for(int i=1;i<=top1;i++){
		int dir;
		if(stk[i][0]!=0){
			dir=op1*stk[i][0];
			if(dir==1) putchar('E');
			else putchar('W');
		}else{
			dir=op2*stk[i][1];
			if(dir==1) putchar('N');
			else putchar('S');
		}
	}
	return 0;
}
