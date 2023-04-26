#include <stdio.h>
int table[3]={0,1,-1};
void f1(char num[],int ab[]);     //将小数点之后的数转成分子分母，分子存于ab[1],分母存于ab[2] 
void f2(char num[],int ab[]);     //将小数点之前的数转成十进制存于ab[0]中 
int main(){
	char num[100];
	int ab[3]={0,0,1};
	scanf("%s",num);
	f2(num,ab);
	if(ab[1]<0&&ab[0]>0){
		printf("%d %d %d",ab[0]-1,ab[2]-ab[1],ab[2]);
	}else if(ab[1]>0&&ab[0]<0){
		printf("%d %d %d",ab[0]+1,ab[2]-ab[1],ab[2]);
	}else if(ab[1]==0){
		printf("%d",ab[0]);
	}else{
		printf("%d %d %d",ab[0],ab[1],ab[2]);
	}
} 
void f1(char num[],int ab[]){
	int i;
	for(i=0;num[i];i++){
		ab[1]=ab[1]*3+table[num[i]-'0'];
		ab[2]=ab[2]*3;
	}
}
void f2(char num[],int ab[]){
	int i;
	for(i=0;num[i];i++){
		if(num[i]!='.'){
			ab[0]=ab[0]*3+table[num[i]-'0'];
		}else{
			f1(num+i+1,ab);
		}
	}
}