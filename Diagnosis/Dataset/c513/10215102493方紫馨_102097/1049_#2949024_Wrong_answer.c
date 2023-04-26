#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct {
	char w[15];
}W;
int cmp(const void*p1,const void*p2){
	W*a = (W*)p1;
	W*b = (W*)p2;
	return strcmp(a->w,b->w);
}
int main()
{
	int T;
	scanf("%d",&T);
	getchar();
	for(int k=0;k<T;k++){
	char s[510];
	gets(s);
	W word[300];
	int a=0,b=0;
	for(int i=0;i<strlen(s);i++){
		if(s[i]==' '||s[i]==','||s[i]=='!'||s[i]=='.'||s[i]=='?'){
			word[a].w[b]='\0';
			a++;b=0;
			continue;
		}
		word[a].w[b]=s[i];b++;
	}
	qsort(word,a+1,sizeof(W),cmp);
	printf("case #%d:\n",k);
	printf("%s ",word[0].w);
	for(int i=1;i<a;i++){
		if(strcmp(word[i].w,word[i-1].w)!=0)
			printf("%s ",word[i].w);
	}
	if(strcmp(word[a-1].w,word[a].w)!=0)
			printf("%s",word[a].w);
	printf("\n");
}
	return 0;

}