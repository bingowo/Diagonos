#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cnt;                                      //消除最多几个字符 
char* erase(char *t){
	char* p=malloc(101*sizeof(char));
	int i=0,j=0,k;
	for(;t[i];i++){
		if(t[i]==t[i+1]){
			for(k=i;t[k];k++){
				if(t[k]==t[k+1]){
					i++;cnt++; 
				}
				else break;
			}
			cnt++;
		}else{
			p[j]=t[i];
			j++;
		}
	}
	p[j]=0;
	free(t);
	return p;
}
int judge(char *t){
	int i;
	for(i=0;t[i];i++){
		if(t[i]==t[i+1]){
			return 1;
		}
	}
	return 0;
}
void f2(char* s){
	int ret=cnt;
	int j,i;                               //j代表忽略下标为j的一位
	for(i=0;s[i];i++){
		int l=2,temp;
		for(j=1;i-j>=0&&s[i+j];j++){
			if(s[i-j]==s[i+j]){
				l+=2; 
			}else{
				break;
			}
		}
		temp=ret+l;
		if(cnt<temp){
			cnt=temp;
		}
	}
	free(s);
}
void f1(char *s){
	while(judge(s)){
		s=erase(s);
	}
	f2(s);
}
int issame(char *s){
	int i;
	for(i=0;s[i+1];i++){
		if(s[i]!=s[i+1]){
			return 0;
		}
	}
	return 1;
}
int main(){
	int t,i;scanf("%d",&t);
	for(i=0;i<t;i++){
	    printf("case #%d:\n",i);
		cnt=0;
		char* num=malloc(101*sizeof(char));
		scanf("%s",num);
		if(issame(num)){
			printf("%d\n",strlen(num)+1);
		}else{
			f1(num);       //消到无法消 ，并调用f2 (找长度最大的对称子字符串) 
			//f2(num);    错误，num作为一个变量，在函数中的改变只是改变的
			//形参，即num的指向不会发生该变，所以只能在f1中调用f2
			printf("%d\n",cnt);
		}
	}
}