#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h> 
int n,l,cnt=0;
struct node{
	struct node* next[27];
}A[500005];
char s[10005];
void build(){
	struct node *p = &A[0];
	for(int i=0;s[i];i++){
		int val=s[i]-'a';
		if(s[i]=='-') val=26;
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
	for(int i=0;i<27;i++) A[0].next[i]=NULL;
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		build();
	}
	scanf("%s",s);
	struct node* p=&A[0]; 
	int flg=1;
	for(int i=0;s[i];i++){
		int val=s[i]-'a';
		if(s[i]=='-') val=26;
		if(p->next[val]!=NULL){
			//puts("YES");
			putchar(s[i]);
			flg=0;
			p=p->next[val];
		}else{
			//puts("NO");
			if(!flg) putchar(' '),flg=1;
			putchar(s[i]);
			if(A[0].next[val]!=NULL) p=A[0].next[val];
			else p=&A[0],putchar(' '),flg=1; 
		}
	} 
	return 0;
} 
