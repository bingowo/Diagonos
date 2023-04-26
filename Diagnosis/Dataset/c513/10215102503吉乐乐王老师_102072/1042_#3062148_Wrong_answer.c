#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int cmp(const void *a,const void *b){
	return strcmp((char*)a,(char*)b);
}
int main(){
	int t;
	scanf("%d",&t);
	int cas=0;
	while(t--){
		char s[16];
		scanf("%s",s);
		int albet[128]={0};
		for(int i=0;i<strlen(s);i++){
			albet[s[i]]=1;
		}
		char alpha[52];
		int n=0;
		for(int i=0;i<128;i++){
			if(albet[i])alpha[n++]=i;
		}
		int bin[16]={0};
		char ret[100000][16];
		int idx=0;
		for(int i=0;i<pow(2,n)-1;i++){
			bin[n-1]+=1;
			for(int j=n-1;j>0;j--){
				bin[j-1]+=bin[j]/2;
				bin[j]%=2;
			}
			char temp[16];
			char *p=temp;
			for(int j=0;j<n;j++){
				if(bin[j]){
					*p=alpha[j];p++;
				}
			}
			*p='\0';
			strcpy(ret[idx++],temp);
		}
		qsort(ret,idx,sizeof(ret[0]),cmp);
		printf("case #%d:\n",cas++);
		for(int i=0;i<idx;i++){
			printf("%s",ret[i]);
			printf("\n");
		}
	}
}