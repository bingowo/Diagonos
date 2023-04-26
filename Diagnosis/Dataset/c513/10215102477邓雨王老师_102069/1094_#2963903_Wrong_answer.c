#include<stdio.h>
#include<string.h>
int cmp(const void*a,const void*b){  //判断A，B的大小 
    char *x,*y;
    x=(char*)a;
    y=(char*)b;
	if(strlen(x)>strlen(y)) return 1;  //1代表A更大，-1表示B更大，0表示两者相等 
	else if(strlen(x)==strlen(y)){
		return strcmp(x,y);
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
	int lines;
	scanf("%d",&lines);
	char s[lines][121];
	int i;
	for(i=0;i<lines;i++){
		scanf("%s",&s[i]);
	}
	qsort(s,lines,sizeof(s[0]),cmp);
	printf("%s",minus(s[lines-1],s[0]));
} 