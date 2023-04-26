#include<string.h>
#include<stdio.h>
int pd(char s[],char c[]){  //判断A，B的大小 
	if(strlen(s)>strlen(c)) return 1;  //1代表A更大，-1表示B更大，0表示两者相等 
	else if(strlen(s)==strlen(c)){
		return strcmp(s,c);
	} 
	else return -1;
}
char* minus(char s[],char c[]){ //此函数默认s代表的数值比c大 
	int len1=strlen(s);
	int len2=strlen(c);
	int i,j,temp=0,t=1;
	i=len1-1;j=len2-1;
	while(i>=0&&j>=0){
		if(s[i]<c[j]){
			s[i]=s[i]+':'-c[j];   //":在ascii码表中排在9的后面一格"
			while(s[i-t]=='0'){
				s[i-t]='9';
				t++;
			}
			s[i-t]-=1;
			t=1;
			i--;
		}
		else{
			s[i]=s[i]-c[j]+'0';
			i--;
		}
		if(j==0&&i!=0){j=0;c[j]='0';}
		else j--;
	}
	for(i=0;s[i]=='0';i++);
	return s+i; 
} 
int main(){
	char s[501],c[501];
	while(scanf("%s %s",&s,&c)!=EOF){
		if(pd(s,c)==1) printf("%s\n",minus(s,c));
		else if(pd(s,c)==0) printf("0\n");
		else printf("-%s\n",minus(c,s));
	}
	return 0;
}