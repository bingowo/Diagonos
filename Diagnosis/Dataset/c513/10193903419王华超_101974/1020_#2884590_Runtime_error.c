#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
typedef struct{
	int time[5],size;
	char name[64];
}file;
int namecmp(const void* p1,const void* p2){
	file a=*((file*)p1),b=*((file*)p2);
	return strcmp(a.name,b.name);
}
int sizecmp(const void* p1,const void* p2){
	file a=*((file*)p1),b=*((file*)p2);
	return a.size-b.size;
}
int timecmp(const void* p1,const void* p2){
	file a=*((file*)p1),b=*((file*)p2);
	int i;
	for(i=0;i<5;i++){
		if (a.time[i]!=b.time[i]){
			return a.time[i]-b.time[i];
		}
	}
}
int main(int argc, char *argv[]) {
	int n;
	scanf("%d",&n);
	while(n){
		int i;
		file l[100];
		for(i=0;i<n;i++){
			scanf("%d-%d-%d %d:%d %d",&l[i].time[0],&l[i].time[1],&l[i].time[2],&l[i].time[3],&l[i].time[4],&l[i].size);
			gets(l[i].name);
		}
		char judge[12];
		gets(judge);
		if(judge[6]=='N'){
			qsort(l,n,sizeof(l[0]),namecmp);
		}
		else if(judge[6]=='S'){
			qsort(l,n,sizeof(l[0]),sizecmp);
		}
		else{
			qsort(l,n,sizeof(l[0]),timecmp);
		}
		for(i=0;i<n;i++){
			printf("%d-%02d-%02d %02d:%02d %16d%s\n",l[i].time[0],l[i].time[1],l[i].time[2],l[i].time[3],l[i].time[4],l[i].size,l[i].name);
		}
		printf('\n');
		scanf("%d",&n);
	}
	return 0;
}