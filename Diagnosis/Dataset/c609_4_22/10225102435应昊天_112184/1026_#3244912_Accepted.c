#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char s[21];
	int dif;
}str;
int cmp(const void* a,const void* b);
int main(){
	int T;
	int n;
	char tab[27] = {0};
	scanf("%d",&T);
	for(int i= 0;i < T;i++){
		scanf("%d",&n);
		str* p = (str*)malloc(sizeof(str) * (n+1));
		for(int j = 0;j < n;j++){
			scanf("%s",(p+j)->s);
			(p+j)->dif = 0;
			for(int k = 0;(p+j)->s[k] != '\0';k++){
				tab[(p+j)->s[k] - 'A']++;
			} 
			for(int cnt = 0;cnt < 27;cnt++){
				if(tab[cnt] != 0)
					(p+j)->dif++;
			}
			memset(tab,0,sizeof(tab));
		}
		qsort(p,n,sizeof(p[0]),cmp);
		printf("case #%d:\n",i);
		for(int j = 0;j < n;j++){
			printf("%s\n",(p+j)->s);
		}
		free(p);
	}
}
int cmp(const void* a,const void* b){
	str* aa = (str*)a;
	str* bb = (str*)b;
	if(aa->dif == bb->dif)
		return strcmp(aa->s,bb->s);
	else
		return bb->dif - aa->dif;
}