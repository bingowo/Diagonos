#include<stdio.h>
#include<string.h>
void binary(char c,int num[]){
	int a;
	if(c>='0'&&c<='9'){
		a=c-'0';
	}else{
		a=c-'A'+10;
	}	
	for(int j=0;j<4;j++){
		num[j]=a%2;
		a/=2;
	}
	for(int i=0;i<2;i++){
		char t;
		t=num[i];num[i]=num[3-i];num[3-i]=t;	
	}
}
int main()
{
	char H[1000];
	scanf("%s",H);
	int B[10000];
	int num[4];
	int i=2,j=0;
	for(;i<strlen(H);i++){
		binary(H[i],num);
		for(int k=0;k<4;k++,j++){
			B[j]=num[k];
			//printf("%d",B[j]);
		}
	}
	//j表示B中数字的个数-1； 
	int qr=0,qi=0,r;
	int a,b;
	i=0;
	while(B[i]==0&&i<4){
		i++;
	}
	if(i==4){
		i=3;
	}
	for(;i<j;i++){
		r=B[i];
		a=r-qr-qi;
		b=qr-qi;
		qr=a,qi=b;
	}
	if(a==0){
		if(b==0)
			printf("0");
		else if(b==1)
			printf("i");
		else
			printf("%di",b);
	}else{
		if(b>0){
			if(b==1)
				printf("%d+i",a,b);
			else
				printf("%d+%di",a,b);
		}else{
			if(b==-1)
				printf("%d-i",a,b);
			else if(b==0)
				printf("%d",a,b);
			else
				printf("%d%di",a,b);
		}		
	}
	return 0;
} 