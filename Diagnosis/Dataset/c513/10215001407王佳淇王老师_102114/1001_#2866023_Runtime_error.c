#include<stdio.h>
#include<math.h>
#include<string.h>
char re(char c[]){
	int i,j,k;
	for(i=0,j=strlen(c)-1;i<j;i++,j--)
	k=c[i];
	c[i]=c[j];
	c[j]=k;

} 
char i2r(int n,char c[],int r)
{
	int i,sign;
	char m;
	if(n<0) printf("-");
	sign=abs(n);
	for(i=0;sign>0;i++){
		m=sign%r;
		sign=sign/r;
		if(m>='0'&&m<='9') c[i]=m+48;
		else c[i]=m+55;
	}
	c[i]=0;
	re(c);
}
int main(){
	int T,N,R;
	char c[100];
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		scanf("%d %d",&N,&R);
		printf("%s\n",i2r(N,c,R));
	}
	return 0;
}