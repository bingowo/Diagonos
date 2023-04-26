#include<stdio.h>
#include<string.h>
int pd(char s[],int i){  //判断s数组第i位的可能性情况 
	if(i==0){   //i为首项的情况 
		if(strlen(s)==1) return 1;
		else{
			if(s[i]==s[i+1]) return 1;
			else return 2;
		}
	}
	else if(i==strlen(s)-1&&strlen(s)!=1){ //i为尾项且数组长度不为1的情况 
		if(s[i]==s[i-1]) return 1;
		else return 2; 
	}
	else{                //此时数组长度一定>=3 
		int count=0;
		if(s[i]!=s[i-1]) count++;
		if(s[i]!=s[i+1]) count++;
		if(s[i-1]!=s[i+1]) count++;
		return count;
	} 
} 
void solve(char s[],int m){
	int p=0;
	int temp=0;
	char c;
	int length=strlen(s);
	while(p<length||temp!=0){
		if(p==length){s[p]=temp+'0';c='0';temp=0;}
		else {c=s[p];s[p]=((s[p]-'0')*m+temp)%10+'0';temp=((c-'0')*m+temp)/10;}
		p++;
	}
	s[p]='\0';
}
void reverse(char s[]){
	int i,j;
	char c;
	for(i=0,j=strlen(s)-1;i<j;i++,j--) //反转
          c=s[i],s[i]=s[j],s[j]=c;
}
int main(){
	char s[1001];
	scanf("%s",&s);
	char s1[1001]={0};
	s1[0]=pd(s,0)+'0';
	int i;
	for(i=1;i<strlen(s);i++){
		solve(s1,pd(s,i));
	}
	reverse(s1);
	printf("%s",s1);
}