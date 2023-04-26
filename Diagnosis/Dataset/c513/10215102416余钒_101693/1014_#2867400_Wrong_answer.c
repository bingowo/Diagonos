#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char num[305];
int n,m,top=0;
int main() {
	scanf("%d%d",&n,&m);
	while(n) num[++top]=n%3,n/=3;
	int up=0;
	for(int i=1;i<=top;i++)
		 num[i]=num[i]+1+up,up=num[i]/3,num[i]%=3;
	if(up) num[++top]=up;
	for(int i=1;i<=top/2;i++){
		int tmp=num[i];
		num[i]=num[top-i+1],num[top-i+1]=tmp;
	}
	int res=-1;
	while(m) m/=3,res++;
	for(int i=1;i<=top-res;i++){
		if(i==1 && up) printf("%c",num[i]+'0');
		else if(num[i]==0) putchar('2');
		else printf("%c",num[i]-1+'0');
	}
	if(res>0){
		putchar('.');
		for(int i=top-res+1;i<=top;i++){
			if(num[i]==0) putchar('2');
			else printf("%c",num[i]-1+'0');
		}
	}
	return 0;
}