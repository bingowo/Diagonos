#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int del(int max,char* string){
	int count,flag,len,k,j;
	count=0;flag=1;len=strlen(string);k=0;
	while(flag){
		flag=0;count=0;		
		for(j=0;j<len;j++){   //开始消除 
			if(string[j]==string[j+1] || string[j]==string[j-1]){
				count++;
			}
			else{
				string[k]=string[j];
				if(string[k]==string[k-1] && k>0)flag=1;
				k++;
			}
		}
		len=k;k=0;
	}
	return max>count?max:count;  //相比之下返回最大值 
}

int main() {
	int T,max,i,j,z,k,x; 
	char string[101],t[101];
	char chosen[]="ABC";
	scanf("%d",&T);
	for(i=0;i<T;i++){
		max=0;
		scanf("%s",string);  //输入字符串
		for(j=0;j<strlen(string);j++){  //插入字符的地方 
			for(k=0;k<3;k++){
				z=0;x=0;
				while(z<=strlen(string)){
					if(z==j)t[z]=chosen[k];  //插入字符
					else{
						t[z]=string[x];x++;
					}
					z++;
				}
				max=del(max,t);
			}
		} 
		printf("case #%d:\n%d\n",i,max);
	}
	return 0;
}