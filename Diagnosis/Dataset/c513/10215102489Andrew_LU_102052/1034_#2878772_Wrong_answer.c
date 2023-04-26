#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
double pi[27];
int cmp1(const void* x,const void* y){
	char a=*(char *)x,b=*(char *)y;
	if(a>='a') a=a-'a';
	else a=a-'A';
	if(b>='a') b=b-'a';
	else b=b-'A'; 
	if(pi[a]!=pi[b]) return pi[a]<pi[b];
	else return a>b;
}
int main(){
	int j=0,i;
	int n;
	scanf("%d",&n);
	while(n--){
		char v[505];
		for(i=0;i<26;i++){
			scanf("%lf",&pi[i]);
		}
		scanf("%s",v);
		qsort((void *)v,strlen(v),sizeof(v[0]),cmp1);
		printf("case #%d:\n",j);
		printf("%s\n",v);
		j++;
	}
}