#include <stdio.h>
#include <string.h>
#define M 500
void input(int num[]){
	char s[M+1];scanf("%s",s);
	int i,j,k;
	for(i=0;s[i]&&s[i]!='.';i++);
	for(j=i-1,k=M;j>=0;j--,k--){
		num[k]=s[j]-'0';
	}
	for(j=i+1,k=M+1;s[j];j++,k++){
		num[k]=s[j]-'0';
	}
//	for(i=0;i<1000;i++){
//		printf("%d",num[i]);
//	}printf("\n");
}
void add(int a[],int b[],int c[],int n){
	int i;
	for(i=2*M;i>M+n;i--){
		if(a[i]+b[i]>9){
			a[i-1]+=(a[i]+b[i])/10;
			c[i]+=(a[i]+b[i])%10;
		}else{
			c[i]+=a[i]+b[i];
		}
	}
	if(c[M+n+1]>4)a[M+n]+=1;
	for(i=M+n;i>0;i--){
		if(a[i]+b[i]>9){
			a[i-1]+=(a[i]+b[i])/10;
			c[i]+=(a[i]+b[i])%10;
		}else{
			c[i]+=(a[i]+b[i])%10;
		}
	}
//	for(i=0;i<=2*M;i++){
//		printf("%d",c[i]);
//	}printf("\n");
}
void output(int num[],int n){
	int i;
	while(i<=M&&num[i]==0)i++;
	if(i==M+1)printf("0.");
	else{
		while(i<=M){
			printf("%d",num[i]);i++;	
		}
		printf(".");
	}
	while(i<=M+n){
		printf("%d",num[i]);i++;
	}
	printf("\n");
}
int main(){
    int a[2*M+1]={0},b[2*M+1]={0},c[2*M+1]={0};int n;
    input(a);input(b);
    scanf("%d",&n);
    add(a,b,c,n);
    output(c,n);
}