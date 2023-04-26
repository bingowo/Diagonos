#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int T,n,l;
char s[10005];
int id[10005],cnt=0;
int cmp(const void* a,const void* b){
	int x=*(int *)a,y=*(int *)b;
	return strcmp(s+x,s+y);
}
int main() {
	scanf("%d\n",&T);
	for(int c=0;c<T;c++){
		gets(s+1);
		l=strlen(s+1);
		cnt=0;
		for(int i=1;i<=l;i++){
			if(s[i]<'a'||s[i]>'z') s[i]='\0';
			else{
				id[++cnt]=i;
				while(s[i]>='a'&&s[i]<='z') i++;
				i-=1;
			}
		}
		qsort(id+1,cnt,sizeof(int),cmp);
		printf("case #%d:\n",c);
		for(int i=1;i<=cnt;i++)
			if(i==cnt||strcmp(s+id[i],s+id[i+1])) printf("%s ",s+id[i]);
		puts("");
	}
	return 0;
}