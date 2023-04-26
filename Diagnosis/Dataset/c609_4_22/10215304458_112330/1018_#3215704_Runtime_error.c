#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b){
	return *(int *)a-*(int *)b;
}
int main(){
	int n,i,p,ans=0,num[10010];
	scanf("%d",&n);
	for(i=0;i<n;++i) scanf("%d",&num[i]);
	qsort(num,n,sizeof(num[0]),cmp);
	for(i=0;i<n;++i){
		if(i%2) p+=num[i],ans+=p;
		else p=-num[i];
	}
	printf("%d",ans);
	return 0;
} 