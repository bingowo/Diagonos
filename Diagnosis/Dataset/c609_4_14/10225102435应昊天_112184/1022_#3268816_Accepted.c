#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void* a,const void* b);
int main(){
	int n;
	scanf("%d",&n);
	char** s = (char**)malloc(sizeof(char*) * n);
	int cnt;
	for(cnt = 0;cnt < n;cnt++){
		char tmp[1000001];
		scanf("%s",tmp); 
		int l = strlen(tmp);
		s[cnt] = (char*)malloc(sizeof(char)*(l+1));
		strcpy(s[cnt],tmp);
	}
	qsort(s,cnt,sizeof(s[0]),cmp);
	for(int i = 0;i < cnt;i++){
		printf("%s\n",s[i]);
	}
	free(s);
	return 0;
}
int cmp(const void* a,const void* b){
	char* aa = *(char**)a;
	char* bb = *(char**)b;
	while(*aa != '@')
		aa++;
	while(*bb != '@')
		bb++;
	if(strcmp(aa,bb) == 0)
		return strcmp(*(char**)b,*(char**)a);
	else
		return strcmp(aa,bb);
} 