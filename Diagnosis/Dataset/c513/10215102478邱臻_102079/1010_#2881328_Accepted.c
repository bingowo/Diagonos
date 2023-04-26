#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void reverse(char *num,int total){
	int i=0,j=total-1;
	char c;
	for(i=0,j=total-1;i<=j;i++,j--){
		c=num[i];num[i]=num[j];num[j]=c;
	}
}

void bin(int a,int total,char* num){
	int len1=0,b,j;
	while(a>0){
		b=a%2;a=a/2;
		num[len1]=b+'0';
		len1++;
	}
	if(len1<total){
		for(j=0;j<total-len1;j++){
			num[len1+j]='0';
		}
	}  //total是字符串的总长度 
	reverse(num,total);
}

int main() {
	char n[500],num1[5];
	char num[10000];
	int len,k,i,j,a,total,z;
	scanf("%s",n);
	printf("0001");
	len=strlen(n);
	bin(len,10,num);
	k=0;
	while(k<10){
		printf("%c",num[k]);
		k++;
	}   //数字个数输出 
	i=0;
	while(n[i]!='\0'){
		j=0;
		while(j<3 && i<len){
			num1[j]=n[i];
			j++;i++;
		}  //三个数字放入一个字符数组 
		if(j==3){
			total=10;a=atoi(num1);
			bin(a,total,num); //二进制转换
			k=0;
			while(k<total){
				printf("%c",num[k]);k++;
			} 
		}
		if(j==2){
			total=7;
			a=(num1[0]-'0')*10+(num1[1]-'0');
			bin(a,total,num); //二进制转换
			k=0;
			while(k<total){
				printf("%c",num[k]);k++;
			}
		}
		if(j==1){
			total=4;
			a=num1[0]-'0';
			bin(a,total,num); //二进制转换
			k=0;
			while(k<total){
				printf("%c",num[k]);k++;
			}
		}
	}
	return 0;
}