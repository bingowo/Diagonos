#include<stdio.h>
#include<stdlib.h>
int cha(int xx,int y){
	char a[500];
	int l=1;
	int x;
	if(xx<0){
		x=-xx;
		printf("-");
	}
	else x=xx;
	while(x>=1){
		int t=x%y;
		x=x/y;
		if(t<10)
		 a[l]=t+'0';
		else a[l]=t-10+'A';
		l++;
	}
	int k;
	for(k=l-1;k>=1;k--){
		printf("%c",a[k]);
	}
	printf("\n");
}
int main(){
	int n,i,j,a;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&a,&j);
		cha(a,j);
	}
} 