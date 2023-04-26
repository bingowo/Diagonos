#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h> 
int n,l,cnt=0;
struct node{
	struct node* next[53];
}A[400005];
char s[10005];
int get(char c){
	if(c==0) return -1;
	if(c>='a'&&c<='z') return c-'a';
	else if(c=='-') return 26;
	else return c-'A'+27;
}
void build(){
	struct node *p = &A[0];
	for(int i=0;s[i];i++){
		int val=get(s[i]);
		if(p->next[val]==NULL){
			cnt++;
			for(int j=0;j<27;j++) 
				A[cnt].next[j]=NULL;
			p->next[val]=&A[cnt];
			p=&A[cnt];
		}
		else p=p->next[val]; 
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<53;i++) A[0].next[i]=NULL;
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		build();
	}
	scanf("%s",s);
	struct node* p=&A[0];
	for(int i=0;s[i];i++){
		int val=get(s[i]);
		if(i!=0&&p==&A[0]) putchar(' ');
		putchar(s[i]);
		if(p->next[val]!=NULL) p=p->next[val];
		else p=&A[0];
		int nxtv=get(s[i+1]);
		if(nxtv==-1) continue;
		if(p->next[nxtv]==NULL) p=&A[0];
	} 
	return 0;
} 
