#include<stdio.h>

char* trans(int a,int r){
	int i=0;
	char* num;
	while(a>0){
		if(a%r>9){
			num[i++]=a%r-10+'A';
		}else{
			num[i++]=a%r+'0';
		}		
		a/=r;
	}
	num[i]='\0';i--;
	for(int j=0;j<i;j++,i--){
		char t;
		t=num[j];
		num[j]=num[i];
		num[i]=t;
	}
	return num;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int k=0;k<T;k++){
		printf("case #%d:\n",k);
		int r,n,d,sum=0;
		scanf("%d%d",&n,&r);
		if(r==10){
			while(n>0){
				sum+=n%10;
				n/=10;
			}
			printf("%d\n",sum);
		}else{
			while(n>0){
				sum+=n%r;
				n/=r;			
			}
			char* p=trans(sum,r);
			printf("%s",p);
		}
	}
	return 0;
 } 