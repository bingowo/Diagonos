#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n,l; 
char s[2000005];
struct node{
	int p1,p2,len;
}A[500005];
int check(int p1,int p2,int len){
	for(int i=0;i<len;i++)
		if(s[p1+i]!=s[p2+i]) return s[p1+i]-s[p2+i];
	return 0;
}
int cmp(const void* a,const void* b){
	struct node x=*(struct node *)a,y=*(struct node *)b;
	if(x.len!=y.len) return x.len-y.len;
	else if(check(x.p2,y.p2,x.len)!=0) return check(x.p2,y.p2,x.len);
	else return strcmp(s+x.p1,s+y.p1);
}
int main() {
	l=n=0;
	while(~scanf("%s",s+l)){
		A[++n].p1=l,A[n].p2=-1,A[n].len=-1;
		for(int i=0;s[i+l]!='\0';i++){
			if(s[i+l]>='1'&&s[i+l]<='9'){
				if(A[n].len==-1) A[n].len=0;
				A[n].len++;
				if(A[n].p2==-1) A[n].p2=l+i;
			}
			else if(s[i+l]=='0'){
				if(A[n].len>0) A[n].len++;
				if(A[n].len==-1) A[n].len=0;
			} 
		}
		l+=strlen(s+l)+1;
	}
	qsort(A+1,n,sizeof(struct node),cmp);
	for(int i=1;i<=n;i++) printf("%s ",s+A[i].p1);
	return 0;
}