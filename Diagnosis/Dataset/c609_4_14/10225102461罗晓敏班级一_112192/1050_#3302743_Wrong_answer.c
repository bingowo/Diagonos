#include <stdio.h>
#include <string.h>
#define M 1000
void input(int num[]){
	char s[501];scanf("%s",s);
	int i,j,k;
	for(i=0;s[i]&&s[i]!='.';i++);
	for(j=i-1,k=499;j>=0;j--,k--){
		num[k]=s[j]-'0';
	}
	for(j=i+1,k=500;s[j];j++,k++){
		num[k]=s[j]-'0';
	}
//	for(i=0;i<1000;i++){
//		printf("%d",num[i]);
//	}printf("\n");
}
void add(int a[],int b[],int c[],int n){
	int i;
	for(i=999;i>=500+n;i--){
		if(a[i]+b[i]>9){
			c[i-1]++;
			c[i]=a[i]+b[i]-10;
		}else{
			c[i]=a[i]+b[i];
		}
	}
	if(c[502]>4)c[501]+1;
	for(i=501;i>=0;i--){
		if(a[i]+b[i]>9){
			c[i-1]++;
			c[i]=a[i]+b[i]-10;
		}else{
			c[i]=a[i]+b[i];
		}
	}
	for(i=0;i<1000;i++){
		printf("%d",c[i]);
	}printf("\n");
}
void output(int num[],int n){
	int i;
	while(i<500&&num[i]==0)i++;
	if(i==500)printf("0.");
	else{
		while(i<500){
			printf("%d",num[i]);i++;	
		}
		printf(".");
	}
	while(i<500+n){
		printf("%d",num[i]);i++;
	}
	printf("\n");
}
int main(){
    int a[M]={0},b[M]={0},c[M]={0};int n;
    input(a);input(b);
    scanf("%d",&n);
    add(a,b,c,n);
    output(c,n);
}