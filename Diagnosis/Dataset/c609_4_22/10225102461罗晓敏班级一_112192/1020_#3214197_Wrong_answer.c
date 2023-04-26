#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	char s[31];
	int isnum;
	int a;
}sta; 
int f1(char a[]){
	int i=0,ret=0;
	while(isdigit(a[i])==0)i++;
	while(isdigit(a[i])){
		ret=ret*10+a[i]-'0';
		i++;
	}
	return ret;
}
int f2(const void* a,const void* b){
	if((*(sta*)a).isnum==0&&(*(sta*)b).isnum==0){
		return strcmp((*(sta*)a).s,(*(sta*)b).s);
	}
	if((*(sta*)a).isnum==1&&(*(sta*)b).isnum==0){
		return 1;
	}else if((*(sta*)a).isnum==0&&(*(sta*)b).isnum==1){
		return -1;
	}else if((*(sta*)a).a!=(*(sta*)b).a){
		return (*(sta*)a).a-(*(sta*)b).a;
	}else{
		return strcmp((*(sta*)a).s,(*(sta*)b).s);
	}
}
int main(){
	int i,j;
	sta *num=(sta*)malloc(100*sizeof(sta));
	for(i=0;scanf("%s",num[i].s)!=EOF;i++){
		num[i].isnum=0;
		for(j=0;num[i].s[j];j++){
			if(isdigit(num[i].s[j])){
				num[i].isnum=1;
				num[i].a=f1(num[i].s);
				break;
			}	
		}
	}
	for(j=0;j<i;j++){
		printf("%s %d %d\n",num[j].s,num[j].isnum,num[j].a);
	}
	qsort(num,i,sizeof(sta),f2);
	for(j=0;j<i;j++){
		printf("%s%c",num[j].s,j==i-1?'\n':' ');
	}
} 