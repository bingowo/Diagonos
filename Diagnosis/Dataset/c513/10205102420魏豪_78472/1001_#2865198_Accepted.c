#include<stdio.h>
void trans(int n,int r){
	char alph[37]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char a[1000];
	int num,i=0,temp=0;
	if(n<0) num=-n;
	else num=n;
	while(num>0){
		temp=num%r;
		a[i]=alph[temp];
		i++;
		num=num/r;
	}
	if(n<0) printf("-");
	for(i=i-1;i>=0;i--){
		printf("%c",a[i]);
	}
	printf("\n");
}
int main(){
	int t,n,r;
	scanf("%d",&t);
	for(int k=0;k<t;k++){
		scanf("%d %d",&n,&r);
		trans(n,r);
	}
	return 0;
} 