#include <stdio.h>
char order[27];
int f1(char a){
	int i;
	if(a==0)return -1;
	char b=toupper(a);
	for(i=0;i<26;i++){
		if(b==order[i]){
			return i;
		}
	}
}
int f2(const void* a,const void* b){
	int i;
	char *c=(char*)a,*d=(char*)b;
	for(i=0;c[i]||d[i];i++){
		if(f1(c[i])>f1(d[i])){
			return 1;
		}else if(f1(c[i])<f1(d[i])){
			return -1;
		}
	}
}

int main(){
	int i,j;
	char num[100][21];
	while(scanf("%s",order)!=EOF){
		i=0;
		getchar();
		scanf("%s",num[i]);
		for(i=1;getchar()!='\n';i++)scanf("%s",num[i]);
		qsort(num,i,sizeof(num[0]),f2);
		for(j=0;j<i;j++){
			printf("%s%c",num[j],j==i-1?'\n':' ');
		}
	}
}