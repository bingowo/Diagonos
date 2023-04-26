#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void reverse(char *s,int k){
	int i=0,j;
	char c;
	for(i=0,j=k-1;i<=j;i++,j--){
		c=s[i];s[i]=s[j];s[j]=c;
	}
}
int main() {
	char alpha[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"};
	char s[101],t[1000],new[7];
	int T,n,i,j,k,x,y,count,result,a,flag;
	scanf("%d",&T);
	getchar();
	for(i=0;i<T;i++){
		for(j=0;j<101;j++)s[j]='\0';
		for(j=0;j<1000;j++)t[j]='\0';
		scanf("%s",s);
		reverse(s,strlen(s));
		printf("case #%d:\n",i);
		k=0;
		for(j=0;j<strlen(s);j++){  //对字符串内的每个字符进行操作 
			n=s[j];flag=k;
			while(n!=0){
				a=n%2;n=n/2;
				t[k++]=a+'0';
			}  //转化为二进制
			while(k-flag!=8){
				t[k++]='0';
			}  //保证是八位二进制 
		}
		reverse(t,k);  //倒置字符串 
		while(k%6!=0){
			t[k++]='0';
		}  //位数是6的倍数 
		t[k]='\0';j=0;x=0;count=0;
		while(j<=k){
			if(x<6){
				new[x++]=t[j];
			}
			else {
				result=0;
				for(y=0;y<6;y++){
					result=result*2+new[y]-'0';
				}  //转化为十进制 
				printf("%c",alpha[result]);
				x=0;count++;
				for(y=0;y<7;y++)new[y]='\0';
				new[x++]=t[j];
			}
			j++;
		}  //输出一个字符
		while(count<4){
			printf("=");
			count++;
		} 
		printf("\n");
	}
	return 0;
}