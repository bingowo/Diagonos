#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
int cmp(const void*a,const void*b);
int main(){
	int p[26]={0};
	char s[27];
	while(scanf("%s",s)!=EOF){
		for(int i=0;i<26;i++){
			p[s[i]-'A']=i;
		}
	}
	char str[2200];
	char a[100][21];
	int count=0;
	gets(str);
	int i=0,j;
	while(1){
		j=0;
		while(str[i]!=' '&&str[i]) a[count][j++];
		a[count][j]='\0';
		count++;
		if(!str[i]) break;
		else i++;
	}
	qsort(a,count,sizeof(a[0]),cmp);
	int k=0;
	for(;k<count-1;k++) printf("%s ",a[k]);
	printf("%s\n",a[k]);
	return 0;

}
int cmp(const void*a,const void*b){
	char*s1,*s2;
	char ch1,ch2;
	s1=(char*)a;s2=(char*)b;
	while(*s1&&*s2){
		ch1=(*s1)>='a'?*s1-32:*s1;
		ch2=(*s2)>='a'?*s1-32:*s2;
		if(p[ch1-'A']!=p[ch2-'A']) return p[ch1-'A']-p[ch2-'A'];
		else{	s1++;s2++;}
		if(*s1==0) return -1;
		else return 1;
	}
}