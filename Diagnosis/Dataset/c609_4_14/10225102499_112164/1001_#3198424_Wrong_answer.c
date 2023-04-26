#include<stdio.h>

int DtoR(long long x,int r){
	int c[50],i=0,j=0,k=0,n;
	char num[36]={'0','1','2','3','4','5','6','7','8','9',};
	if(x<0){
		x=-x;
		printf("-");
	}
	do{
		c[i]=x%r;
		x/=r;
		i++;
	}
	while(x/r>0||x%r!=0);
	for(j=0;j<26;j++)
		num[j+10]=j+'A';
	for(k=i-1;k>=0;k--){
		n=c[k];
		printf("%c",num[n]);
	}
}

int main(){
	int n,b[10],i=0;
	long long a[10];
	scanf("%d",&n);
	for(;i<n;i++)
		scanf("%lld %d",&a[i],&b[i]);
	for(i=0;i<n;i++){
		DtoR(a[i],b[i]);
	}
	return 0;
}