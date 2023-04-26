#include<stdio.h>
int main(){
	int t,i,x,y,j,k;
	char m,a[100];
	scanf("%d\n",&t);
	int n[t],r[t];
	for(i=0;i<t;i++) scanf("%d %d\n",&n[i],&r[i]);
	for(i=0;i<t;i++){
		if(n[i]<0){
			printf("-");
			y=-n[i];
		}
		else y=n[i];
		j=0;
		while(y!=0){
			x=y%r[i];
			y=y/r[i];
			if(x<10) m=48+x;
			else m=55+x;
			a[j]=m;
			j++;
		}
		for(k=j-1;k>=0;k--) printf("%c",a[k]); 
		printf("\n");
	}
	return 0;
} 