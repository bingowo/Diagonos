#include<stdio.h>
#include<string.h>
int max(int a,int b){
	return a>b?a:b;
}
int elimination(char *temp,int len){
	char trans[102];
	int idx=0;
	if(len<=1)return 0;
	if(temp[0]!=temp[1])trans[idx++]=temp[0];
	for(int i=1;i<len-1;i++){
		if(temp[i]!=temp[i-1]&&temp[i]!=temp[i+1])
			trans[idx++]=temp[i];
	}
	if(temp[len-1]!=temp[len-2])trans[idx++]=temp[len-1];
	trans[idx]='\0';
	int ret=len-idx;
	strcpy(temp,trans);
	return ret==0?ret:ret+elimination(temp,idx);
}
void insert(char *s,char *temp,char ch,int pos){
	strcpy(temp,s);
	char *p=s+pos;
	temp[pos]=ch;
	temp[pos+1]='\0';
	strcat(temp,p);
}
int main(){
	int t;
	scanf("%d",&t);
	int cas=0;
	while(t--){
		char s[101];
		scanf("%s",s);
		int len=strlen(s);
		int ret=0;
		for(int i=0;i<len+1;i++){
			char temp[102];
			insert(s,temp,'A',i);
			ret=max(ret,elimination(temp,len+1));
			insert(s,temp,'B',i);
			ret=max(ret,elimination(temp,len+1));
			insert(s,temp,'C',i);
			ret=max(ret,elimination(temp,len+1));
		}
		printf("case #%d:\n%d\n",cas++,ret);
	}
}