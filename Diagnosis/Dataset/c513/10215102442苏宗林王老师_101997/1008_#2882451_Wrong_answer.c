#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

int main(){
	int re,i,m,n,x,y;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		re=0;
		for(int j=0;j<32;j++){
			m=(x&1)^(y&1);
			//printf("%d\n",m);
			if(m==1){
				re++;
			}
			x=x>>j;
			y=y>>j;
		}
		printf("%d\n",re);
	}
	return 0;
}