#include <stdio.h>
#include <string.h>
int fun(char x);
long long power(int x,int y);
int DtoR(long long x,int r);

int main(){
	int p,q,i,t;
	long long n=0;
	char a[100];
	memset(a,-1,sizeof(a));
	scanf("%d %s %d",&p,a,&q);
	for(i=0;a[i]!=EOF;i++);
	t=i-2;
	i-=2;
	for(;i>=0;i--){
		n+=fun(a[i])*power(p,t-i);
	}
	DtoR(n,q);
} 

int fun(char x){
	if (x>='0'&&x<='9')
		return (x-'0');
	else if (x>='a')
		return (x-'a'+10);
	else return (x-'A'+10);
}

long long power(int x,int y){
	long long t=1;
	int j;
	for(j=0;j<y;j++)
		t*=x;
	return t;
}

int DtoR(long long x,int r){
	int c[50],i=0,j=0,k=0,n;
	char num[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F',};
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
	for(k=i-1;k>=0;k--){
		n=c[k];
		printf("%c",num[n]);
	}
}

