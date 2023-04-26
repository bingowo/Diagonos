#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int T,n;
char s[1005],tmp[1005];
int main() {
	scanf("%d\n",&T);
	for(int c=0;c<T;c++){
		gets(s+1);
		int l=strlen(s+1),ans=0;
		for(int i=1;i<=l;i++)
			if(s[i]>='A'&&s[i]<='Z') s[i]=s[i]-'A'+'a';
		for(int i=1;i<=l;i++){
			int pos=0,j;
			for(j=i;s[j]!=' ' && s[j]!=0;j++) tmp[pos++]=s[j];
			tmp[pos]='\0';
			//printf("!!  %s\n",tmp);
			i=j;
			if(pos&&strcmp(tmp,"the")&&strcmp(tmp,"a")&&strcmp(tmp,"an")&&strcmp(tmp,"of")&&strcmp(tmp,"for")&&strcmp(tmp,"and"))
				ans++;
		}
		printf("case #%d:\n%d\n",c,ans);
	}
	return 0; 
}