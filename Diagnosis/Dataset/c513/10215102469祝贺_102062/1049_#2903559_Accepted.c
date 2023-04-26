#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char s[510][510],sp=0;
int myscanf(){
	char buf[510];int top=0;
	char c;
	while((c=getchar())!=' ' && c!=',' && c!='.' && c!='!' && c!='?' && c!='\n' && c!=EOF){
		buf[top++]=c;
	}
	for(int i=0;i<top ;i++) s[sp][i]=buf[i];
	s[sp][top]=0;
	if(top>0) sp++;
	if(c==EOF || c=='\n')return -1;
	else return 1;
}
int cmp(const void*a ,const void*b){
	char*str1=(char*)a,*str2=(char*)b;
	return strcmp(str1,str2)<0?-1:1;
}
int main(){
	int t;scanf("%d",&t);getchar();
	for(int m=0;m<t;m++){
		while(myscanf()!=-1);
		qsort(s,sp,sizeof(s[0]),cmp);
		int i=0;
		printf("case #%d:\n",m);
		for(int j=1;j<sp;j++){
			if(strcmp(s[i],s[j])!=0){
				strcpy(s[++i],s[j]);
			}
		}
		for(int e=0;e<=i;e++){
			printf("%s ",s[e]);
		}
		printf("\n");
		sp=0;
	}
	return 0;
} 
 