#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LL long long
LL x,p;
int stk[100005],top=0,flg=1,mov=0;
int main() {
	scanf("%lld%lld",&x,&p);
	if(x<0) flg=-1,x=-x;
	while(x>0){
		stk[++top]=x%3;
		x/=3;
	}
	while(p>1) p/=3,mov++;
	for(int i=1;i<=top;i++){
		stk[i]++;
		stk[i+1]+=stk[i]/3;
		stk[i]%=3;
	}
	for(int i=1;i<=top;i++) stk[i]--;
	if(stk[top+1]>0) stk[top++];
	if(flg==-1)
		for(int i=1;i<=top;i++) stk[i]=-stk[i];
	int les=1;
	while(les<=top && stk[les]==0) les++;
	if(les>top) putchar('0'),exit(0);
	if(mov>=top){
		printf("0.");
		for(int i=mov-top;i>=1;i--) putchar('0');
		for(int i=top;i>=les;i--) printf("%d",stk[i]==-1?2:stk[i]);
	}
	else{
		for(int i=top;i>mov;i--) printf("%d",stk[i]==-1?2:stk[i]);
		if(les<=mov){
			putchar('.');
			for(int i=mov;i>=les;i--) printf("%d",stk[i]==-1?2:stk[i]);
		}
	}
	return 0;
}