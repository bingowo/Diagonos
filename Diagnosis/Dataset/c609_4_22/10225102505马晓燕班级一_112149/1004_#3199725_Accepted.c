#include<stdio.h>
#include<string.h>
int transA_ten(char n[],int A,int len,int *p){
	int ten=0;
	for(int i=0;i<len;i++){
		ten = ten * A + p[n[i]];
	}
	return ten;
}
void transten_B(int n,int B,char *pp){
	if(n>0){			//table映射表
		transten_B(n/B,B,pp);
		printf("%c",pp[n%B]);
	}
	
}
int main(){
	int A,B;
	scanf("%d ",&A);
	char n[50]={0};
	scanf("%s",n);
	scanf("%d",&B);

	int len = strlen(n);
	int table1[128]={0};
	char table2[]="0123456789ABCDEF";
	for(int i='0';i<='9';i++){
		table1[i] = i - '0';
	}
	for(int i='A';i<='F';i++){
		table1[i] = 10 + i - 'A';
		}
	for(int i='a';i<='f';i++){
		table1[i] = 10 + i - 'a';
	}
	int ten=transA_ten(n,A,len,table1);
//	printf("%d\n",ten);
	if(ten == 0)
		printf("0");
	else
		transten_B(ten,B,table2);
	
	return 0;
}