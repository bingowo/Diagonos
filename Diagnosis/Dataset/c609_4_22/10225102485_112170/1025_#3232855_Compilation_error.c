#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int compare1(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}
int main(){
	int m,n;
	scanf("%d%d",&n,&m);
	int s[n]={};
	for(int i=0;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(c==-1){s[b]+=3; s[a]-=1;}
		if(c==1){s[a]+=3; s[b]-=1;}
		if(c==1){s[b]+=1; s[a]+=1;}
	}
	qsort(s,n,sizeof(int),compare1);
	for(int i=0;i<n;i++)printf("%d",s[i]);
	return 0; 
} 