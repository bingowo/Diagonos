#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h> 
int n,l,cnt=0,top;
struct node{
	int end;
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
			A[cnt].end=0;
			for(int j=0;j<27;j++) 
				A[cnt].next[j]=NULL;
			p->next[val]=&A[cnt];
			p=&A[cnt];
		}
		else
			p=p->next[val];
		if(s[i+1]==0) p->end=1; 
	}
}
int main(){
	scanf("%d",&n);
	A[0].end=1;
	for(int i=0;i<53;i++){
		A[0].next[i]=&A[++cnt];
		A[cnt].end=1;
		for(int j=0;j<53;j++) A[cnt].next[j]=NULL;
	}
	
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		build();
	}
	scanf("%s",s);
	struct node* p=&A[0];
	int las1=-1,las2=-1;
	for(int i=0;s[i];i++){
		int val=get(s[i]);
		if(p->end==1) las2=i-1;
		
		if(p->next[val]!=NULL) p=p->next[val];
		else{
			for(int j=las1+1;j<=las2;j++) putchar(s[j]);
			putchar(' ');
			las1=las2;
			p=&A[0];
			i=las2;
		} 
	}
	for(int j=las1+1;s[j];j++) putchar(s[j]);
	return 0;
} 
