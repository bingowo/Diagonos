#include <stdio.h>
#include<stdlib.h>

long long num(char* a){
	int n,havenum=0;
	long long sum=0;
	for(n=0;a[n]!=0;n++){
		if(a[n]>='0'&&a[n]<='9'){
			sum=sum*10+(a[n]-'0');
			havenum=1;
		}
	}
	if(havenum)return sum;
	else return -1;
}

int strnumcmp(const void* a,const void* b){
	int i;
	long long nums,numt;
	char *s=(char*)a,*t=(char*)b;
	nums=num(s),numt=num(t);
	if(nums!=numt)
		return nums-numt;
	else if(nums>-1&&nums!=numt)
		return nums-numt;
	else return strcmp(s,t);
	}


int main(){
	int n,i;
	int a[100][30]={0};
	for(n=0;(scanf("%s",&a[n])!=EOF);n++);
	qsort(a,n,sizeof(a[0]),strnumcmp);
	for(i=0;i<n-1;i++){
		printf("%s ",a[i]);
	}
	printf("%s",a[n-1]);
	return 0;
}