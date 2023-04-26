#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void* a,const void* b);
int main(){
	int n;
	scanf("%d",&n);
	char s[n][1000000/n];
	int cnt;
	for(cnt = 0;cnt < n;cnt++){
		scanf("%s",s[cnt]);
	}
	qsort(s,cnt,sizeof(s[0]),cmp);
	for(int i = 0;i < cnt;i++){
		printf("%s\n",s[i]);
	}
	return 0;
}
int cmp(const void* a,const void* b){
	char* aa = (char*)a;
	char* bb = (char*)b;
	char* p = strchr(aa,'@');
	char* q = strchr(bb,'@');
	char* user_a = (char*)malloc(sizeof(char) * 10000);
	char* user_b = (char*)malloc(sizeof(char) * 10000);
	memcpy(user_a,aa,p-aa);
	memcpy(user_b,bb,q-bb);
	char* domain_a = (char*)malloc(sizeof(char) * 100);
	char* domain_b = (char*)malloc(sizeof(char) * 100);
	memcpy(domain_a,p+1,aa+strlen(aa)-1-p);
	memcpy(domain_b,q+1,bb+strlen(bb)-1-q);
	if(strcmp(domain_a,domain_b) == 0)
		return strcmp(user_b,user_a);
	else
		return strcmp(domain_a,domain_b);
} 