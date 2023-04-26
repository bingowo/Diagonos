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
	int a=0,b=0;
	W word[300];
	for(int i=0;i<strlen(s);i++){		
		if(s[i]==' '||s[i]==','||s[i]=='!'||s[i]=='.'||s[i]=='?'||i==strlen(s)-1){
			if(i==strlen(s)-1){
				word[a].w[b]=s[i];b++;
			}
			word[a].w[b]='\0';
			if(b!=0&&i!=strlen(s)-1)
				a++;b=0;
			continue;
		}
		word[a].w[b]=s[i];b++;
	}	
	printf("case #%d:\n",k);
	if(a==0)
		printf("%s\n",word[0].w);
	else{
	qsort(word,a+1,sizeof(W),cmp);	
	int i=0;
	while(strlen(word[i].w)==0) i++;
	printf("%s ",word[i].w);
	for(i=i+1;i<a;i++){
		if(strcmp(word[i].w,word[i-1].w)!=0)
			printf("%s ",word[i].w);
	}
	if(strcmp(word[a-1].w,word[a].w)!=0&&a>0)
			printf("%s",word[a].w);
	printf("\n");
	}
}
	return 0;

}