#include <stdio.h>
int cmp(const void* a,const void* b){
	int i,j;char *c=(char*)a,*d=(char*)b;
	for(i=0;c[i];i++){
		if(c[i]=='@')
			break;
	}
	for(j=0;d[j];j++){
		if(d[j]=='@')
			break;
	}
	int ret=strcmp(c+i+1,d+j+1);
	if(ret!=0)return ret;
	else return strcmp(d,c);
}
int main(){
	int n,i,j;
	scanf("%d",&n);
	char num[n][1000000-n];
	for(i=0;i<n;i++){
		scanf("%s",num[i]);
	}
	qsort(num,i,sizeof(num[0]),cmp);
	for(j=0;j<i;j++){
		printf("%s\n",num[j]);
	}
}