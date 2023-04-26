#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
	char s1[100];
	gets(s1);
	int m=strlen(s1);
	int i,flag=0;
	char word;
	for(i=0;i<m;i++){
		if(s1[i]=='='){
			flag=i;
		}
		if(s1[i]>='a'&&s1[i]<='z') word=s1[i];
	}//找到等号的位置并确定方程的未知数
	int sumleft_num=0,sumleft_x=0,sumright_num=0,sumright_x=0;
	int cnt=0,ans=0;
	for(i=0;i<flag;i++){
		if(s1[i-1]=='+'||s1[i-1]=='-'||i==0){
			int j=i;
			int key=0;
			for(j=i;s1[j]!='+'&&s1[j]!='-'&&j!=flag;j++){
				if(s1[j]>='a'&&s1[j]<='z'){
					key+=1;
				}
			}//如果有字母则代表所求的为未知数的系数，将key调整
			cnt=0;
			if(key==0){
				if(i==0||s1[i-1]=='+'){
					for(j=i;s1[j]>=48&&s1[j]<=57;j++){
						cnt++;
					}
					int temp1=0;
					for(j=i;s1[j]>=48&&s1[j]<=57;j++){
						temp1=s1[j]-48;
						sumleft_num+=temp1*pow(10,cnt-1);
						cnt--;
					}	
				}//如果为常数且首符号是加号或者在开始，进行常数的加法运算，结果进行存储。
				if(s1[i-1]=='-'&&i!=0){
					for(j=i;s1[j]>=48&&s1[j]<=57;j++){
						cnt++;
					}
					int temp1=0;
					for(j=i;s1[j]>=48&&s1[j]<=57;j++){
						temp1=s1[j]-48;
						sumleft_num-=temp1*pow(10,cnt-1);
						cnt--;
					}	
				}//如果为常数且首符号是减号，进行常数的减法运算，结果进行存储。
			}
			if(key!=0){
				if(i==0||s1[i-1]=='+'){
					for(j=i;s1[j]>=48&&s1[j]<=57;j++){
						cnt++;
					}
					if(cnt==0) sumleft_x+=1;
					if(cnt!=0){
						int temp2=0;
						for(j=i;s1[j]>=48&&s1[j]<=57;j++){
							temp2=s1[j]-48;
							sumleft_x+=temp2*pow(10,cnt-1);
							cnt--;
						}
					}//如果为未知数系数且首符号是加号或者在开始，进行系数的加法运算，结果进行存储。
				}
				if(s1[i-1]=='-'){
					for(j=i;s1[j]>=48&&s1[j]<=57;j++){
						cnt++;
					}	
					if(cnt==0) sumleft_x-=1;
					if(cnt!=0){
						int temp2=0;
						for(j=i;s1[j]>=48&&s1[j]<=57;j++){
							temp2=s1[j]-48;
							sumleft_x-=temp2*pow(10,cnt-1);
							cnt--;
						}
					}//如果为未知数且首符号是减号，进行系数的减法运算，结果进行存储。
				}
			}
		}
	}//以下是右侧代数式的运算，和上面类似，注意初始化和临界点问题即可
	for(i=flag+1;i<m;i++){
		if(s1[i-1]=='+'||s1[i-1]=='-'||i-1==flag){
			int j=i;
			int key1=0;
			for(j=i;s1[j]!='+'&&s1[j]!='-'&&j!=m;j++){
				if(s1[j]>='a'&&s1[j]<='z'){
					key1+=1;
				}
			}
			ans=0;
			if(key1==0){
				if(i==flag+1||s1[i-1]=='+'){
					for(j=i;s1[j]>=48&&s1[j]<=57;j++){
						ans++;
					}
					int temp3=0;
					for(j=i;s1[j]>=48&&s1[j]<=57;j++){
						temp3=s1[j]-48;
						sumright_num+=temp3*pow(10,ans-1);
						ans--;
					}	
				}
				if(s1[i-1]=='-'){
					for(j=i;s1[j]>=48&&s1[j]<=57;j++){
						ans++;
					}
					int temp3=0;
					for(j=i;s1[j]>=48&&s1[j]<=57;j++){
						temp3=s1[j]-48;
						sumright_num-=temp3*pow(10,ans-1);
						ans--;
					}	
				}	
			}
			if(key1!=0){
				if(i==flag+1||s1[i-1]=='+'){
					for(j=i;s1[j]>=48&&s1[j]<=57;j++){
						ans++;
					}
					if(ans!=0){
					    if(ans==0) sumright_x+=1;
						int temp4=0;
						for(j=i;s1[j]>=48&&s1[j]<=57;j++){
							temp4=s1[j]-48;
							sumright_x+=temp4*pow(10,ans-1);
							ans--;
						}
					}
				}
				if(s1[i-1]=='-'){
					for(j=i;s1[j]>=48&&s1[j]<=57;j++){
						ans++;
					}
					if(ans==0) sumright_x-=1;
					if(ans!=0){
						int temp4=0;
						for(j=i;s1[j]>=48&&s1[j]<=57;j++){
							temp4=s1[j]-48;
							sumright_x-=temp4*pow(10,ans-1);
							ans--;
						}
					}
				}
			}
		}
	}
	double sum;
	double sum_num,sum_x;
	sum_num=sumright_num-sumleft_num;
	sum_x=sumleft_x-sumright_x;
	sum=sum_num/sum_x;
	printf("%c=%.3lf\n",word,sum);//计算求出，保留三位小数
	return 0;
}
