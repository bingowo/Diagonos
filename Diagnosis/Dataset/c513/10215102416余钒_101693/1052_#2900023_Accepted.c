#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int T,n,l,ans[1005],tot;
char s[1005],alp[20][20]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
int cmp(const void* a,const void* b){
	return *(int *)a-*(int *)b;
}
int cnt[256];
void oper(char x,int v){
	if(cnt[x]){
		int p=cnt[x];
		for(int i=0;alp[v][i];i++)
			cnt[alp[v][i]]-=p;
		while(p) ans[++tot]=v,p--;
	}
}
void solve(){
	for(int i='A';i<='Z';i++) cnt[i]=0;
	tot=0;
	for(int i=0;s[i];i++) cnt[s[i]]++;
	oper('X',6),oper('Z',0),oper('W',2),oper('S',7),oper('V',5),oper('F',4),oper('O',1),oper('R',3),oper('H',8),oper('I',9);
	qsort(ans+1,tot,sizeof(int),cmp);
}
int main() {
	scanf("%d\n",&T);
	for(int c=0;c<T;c++){
		scanf("%s",s);
		solve();
		printf("case #%d:\n",c);
		for(int i=1;i<=tot;i++) printf("%d",ans[i]);
		puts("");
	}
	return 0;
}