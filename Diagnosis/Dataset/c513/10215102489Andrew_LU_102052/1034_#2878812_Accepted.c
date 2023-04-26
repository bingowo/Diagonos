#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
float pi[27];
int cmp1(const void* x,const void* y){
	char a=*(char *)x,b=*(char *)y;
	int aaa=a,bbb=b;
	if(a>='a') a=a-'a';
	else a=a-'A';
	if(b>='a') b=b-'a';
	else b=b-'A';
	int aa=a,bb=b;
	//printf("%d %d\n",aa,bb);
	if(pi[aa]!=pi[bb]) 
		return pi[aa]<pi[bb]? 1:-1;
	else if(abs(*(char *)x-*(char *)y)!=32) return *(char *)x>*(char *)y;
	else return *(char *)y-*(char *)x;
}
int main(){
	int j=0,i;
	int n;
	scanf("%d",&n);
	while(n--){
		char v[505];
		for(i=0;i<26;i++){
			scanf("%f",&pi[i]);
		}
		scanf("%s",v);
		//printf("%d\n",strlen(v));
		qsort((void *)v,strlen(v),sizeof(v[0]),cmp1);
		printf("case #%d:\n",j);
		printf("%s\n",v);
		j++;
	}
}
