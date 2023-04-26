#include<stdio.h>
int main(){
	int a,b,m=0,q=1,i=0,j,n[40];
	char c=0,ans[40];
	scanf("%d ",&a);
	while((c=getchar())!=' '){
		if(c>='0'&&c<='9') n[i++]=c-'0';
		else{
			if(c>='A'&&c<='Z') c-='A'-'a';
			n[i++]=c-'a'+10;
		}
	}
	scanf("%d",&b);
	for(j=i-1;~j;--j){
		m+=n[j]*q;
		q*=a;
	}
	i=0;
	if(!m) ans[i++]='0';
	while(m){
		if(m%b<10) ans[i++]=m%b+'0';
		else ans[i++]=m%b-10+'A';
		m/=b;
	}
	for(j=i-1;~j;--j) printf("%c",ans[j]);
    return 0;
}