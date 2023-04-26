#include <stdio.h>

#include <stdlib.h>

#include <string.h>

int n,m;

char s[20005];

int map[300],id[300];

int cmp(const void* a,const void* b){

	int x=*(int *)a,y=*(int *)b;

	for(int i=0;;i++){

		if(*(s+x+i)=='\0' && *(s+y+i)=='\0')  return 0;

		else if(*(s+x+i)=='\0') return -1;

		else if(*(s+y+i)=='\0') return 1;

		else if(map[*(s+y+i)]!=map[*(s+x+i)]) return map[*(s+x+i)]-map[*(s+y+i)];

	}

}

int main() {

	while(~scanf("%s\n",s)){

		for(int i=0;s[i];i++)

			map[s[i]-'A'+'a']=map[s[i]]=i;

		gets(s);

		int n=0;

		for(int i=0;s[i];i++){

			if(s[i]==' '||s[i]=='\n') s[i]='\0';

			if(i==0||s[i-1]=='\0') id[++n]=i;

		}

		qsort(id+1,n,sizeof(int),cmp);

		for(int i=1;i<=n;i++)

			printf("%s ",s+id[i]);

		puts("");

	}

	return 0;

}
