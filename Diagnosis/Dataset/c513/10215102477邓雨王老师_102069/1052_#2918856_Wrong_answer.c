#include<stdio.h>
#include<string.h>
int cmp(const void*a,const void*b){
	int x,y;
	x=*(int*)a;
	y=*(int*)b;
	return x>y;
}
int main(){
	int chance;
	scanf("%d\n",&chance);
	int i;
	for(i=0;i<chance;i++){
		char s[21];
		scanf("%s",&s);
		int b[25]={0};
		int a[11];
		int p=0;  //用来表示数组a的参数 
		int j;
		for(j=0;j<strlen(s);j++){
			b[s[j]-'A']+=1;
		}
		while(b[25]>0){
			a[p++]=0;
			b[25]=b[25]-1;
			b[4]+=-1;
			b[17]+=-1;
			b[14]+=-1;
		}
		while(b[23]>0){
			a[p++]=6;
			b[18]+=-1;
			b[8]+=-1;
			b[23]+=-1;
		}
		while(b[18]>0){
			a[p++]=7;
			b[18]+=-1;
			b[4]+=-2;
			b[21]+=-1;
			b[13]+=-1;
		}
		while(b[21]>0){
			a[p++]=5;
			b[5]+=-1;
			b[8]+=-1;
			b[21]+=-1;
			b[4]+=-1;
		}
		while(b[5]>0){
			a[p++]=4;
			b[5]+=-1;
			b[14]+=-1;
			b[20]+=-1;
			b[17]+=-1;
		}
		while(b[22]>0){
			a[p++]=2;
			b[19]+=-1;
			b[22]+=-1;
			b[14]+=-1;
		}
		while(b[6]>0){
			a[p++]=8;
			b[6]+=-1;
			b[4]+=-1;
			b[8]+=-1;
			b[7]+=-1;
			b[19]+=-1;
		}
		while(b[14]>0){
			a[p++]=1;
			b[14]+=-1;
			b[13]+=-1;
			b[4]+=-1;
		}
		while(b[13]>0){
			a[p++]=9;
			b[13]+=-2;
			b[8]+=-1;
			b[4]+=-1;
		}
		while(b[19]>0){
			a[p++]=3;
			b[19]+=-1;
			b[7]+=-1;
			b[4]+=-2;
			b[17]+=-1;
		}
		qsort(a,p,sizeof(int),cmp);
		printf("case #%d:\n",i);
		for(j=0;j<p;j++){
			printf("%d",a[j]);
		}
		printf("\n");
	}
} 