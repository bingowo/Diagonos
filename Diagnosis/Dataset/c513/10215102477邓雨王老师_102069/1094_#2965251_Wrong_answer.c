#include<stdio.h>
#include<string.h>
char* pd(char s[]){    //用来给负数取正 
	return s+1; 
}
int cmp(const void*a,const void*b){  //判断A，B的大小
    char *s,*c;
	s=(char*)a;
	c=(char*)b; 
    if(s[0]=='-'&&c[0]!='-') return 1;  //s为负，c不为负的情况
	else if(s[0]=='-'&&c[0]=='-'){
		if(strlen(s)>strlen(c)) return 1;
		else if(strlen(s)==strlen(c)) return strcmp(s,c);  
		else return -1;
	}
	else if(s[0]!='-'&&c[0]!='-'){
		if(strlen(s)>strlen(c)) return -1;
		else if(strlen(s)==strlen(c)) return strcmp(c,s);  
		else return 1;
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
char* plus(char s[],char c[],char s1[],char c1[]){   //这里已经假定
	int i,j,t=1;
	if(strlen(s)>strlen(c)){
	for(i=1;i<strlen(s)+1;i++) s1[i]=s[i-1];   //最前面预留一个位置,以防止最高位进位 
	for(i=1+strlen(s)-strlen(c);i<strlen(s)+1;i++) c1[i]=c[i-1+strlen(c)-strlen(s)];}
	else{
			for(i=1;i<strlen(c)+1;i++) c1[i]=c[i-1];   //最前面预留一个位置,以防止最高位进位 
	        for(i=1+strlen(c)-strlen(s);i<strlen(c)+1;i++) s1[i]=s[i-1+strlen(s)-strlen(c)];}
	int x=strlen(s1)-1,y=strlen(c1)-1;
	int max=(strlen(s)>strlen(c))?strlen(s):strlen(c);
	while(x>=0&&y>=0){
		if(s1[x]+c1[y]-'0'>'9'){   //'.'在ascii码表中值为46，排在'0'前面，因此无需考虑'.'+'数字'>'9'的情况 
			s1[x]=s1[x]+c1[y]-':';
			while(s1[x-t]=='9'){
			    s1[x-t]='0';
			    t++;
				
			}
			s1[x-t]+=1;
			x--,y--;
			t=1;
		}
		else{
			s1[x]=s1[x]+c1[y]-'0';
			x--,y--;
		}
	}
	s1[max+1]='\0';
	if(s1[0]=='0') return s1+1; 
	else return s1;
} 
int main(){
	int lines,i;
	char s1[1000],c1[1000];
	for(i=0;i<1000;i++) s1[i]='0',c1[i]='0';
	s1[i]='\0',c1[i]='\0';
	scanf("%d",&lines);
	char s[lines][121];
	for(i=0;i<lines;i++){
		scanf("%s",&s[i]);
	}
	qsort(s,lines,sizeof(s[0]),cmp); //从大到小排列
	for(i=0;i<lines;i++){
		printf("%s\n",s[i]);
	} 
	if(s[0][0]=='-'&&s[lines-1][0]=='-') printf("%s",minus(pd(s[lines-1]),pd(s[0])));
	else if(s[0][0]!='-'&&s[lines-1][0]=='-') printf("%s",plus(s[0],pd(s[lines-1]),s1,c1)); 
	else if(s[0][0]!='-'&&s[lines-1][0]!='-') printf("%s",minus(s[0],s[lines-1]));
	return 0;
} 