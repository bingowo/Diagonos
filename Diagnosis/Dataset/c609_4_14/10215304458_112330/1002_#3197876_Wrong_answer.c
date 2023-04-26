#include<stdio.h>
int main(){
    int t,n,i,j,k,ans,l,pre;
    char s[40];
	scanf("%d",&t);
	for(i=0;i<t;++i){
		scanf("%d",&n);
		j=0;
		while(n){
			s[j++]=(n&1)+'0';
			n>>=1;
		}
		ans=l=1;
		for(k=1;k<j;++k){
			if(s[k]!=s[k-1]) ++l;
			else{
				if(l>ans) ans=l;
				l=1;
			}
		}
		printf("case #%d:%d\n",i,l>ans?l:ans);
	}
    return 0;
}