#include<stdio.h>
#include<string.h>
int main(){
	int t;
	scanf("%d",&t);
	int cas=0;
	while(t--){
		char octal[55];
		scanf("%s",octal);
		int dec[200]={0};
		int len=strlen(octal);
		int number=0;
		for(int i=len-1;octal[i]!='.';i--){
			int temp=octal[i]-'0';
			int j=0;
			do{
				if(j<number)
					temp=temp*10+dec[j];
				else 
					temp=temp*10;
				dec[j++]=temp/8;
				temp%=8;
			}while(temp!=0||j<number);
			number=j;
		}
		printf("case #%d:\n0.",cas++);
		for(int i=0;i<number;i++){
			printf("%d",dec[i]);
		}
		putchar('\n');
	}
}